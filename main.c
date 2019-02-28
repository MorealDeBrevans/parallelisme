#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplir(double * vecteur, int taille){
	for(int i=0;i<taille;i++) vecteur[i]= ( (double)rand() * 100 ) / (double)RAND_MAX;
}

void afficher(double * vecteur, int taille){
	printf("[ ");
	for(int i=0;i<taille-1;i++) printf("%.2f, ",vecteur[i]);
	printf("%.2f ]\n", vecteur[taille-1]);
	printf("\n");
}

double * ajouter(double * vecteur1, double * vecteur2, int taille){
	double * resultat;
	resultat = malloc(taille*sizeof(double));
	for(int i=0;i<taille;i++) resultat[i] = vecteur1[i] + vecteur2[i];
	return resultat;
}

double somme(double* vecteur,int taille) {
	double resultat=0;
	for(int i=0;i<taille;i++) resultat+=vecteur[i];
	return resultat;
}

int main(int argc, char *argv[]) {
	int taille;
	if(argv[1]) taille = atoi(argv[1]);
	else taille = 1024;
	
	int nb_coeurs;
	if(argv[2]) nb_coeurs=atoi(argv[2]);
	else nb_coeurs=1;
	
	omp_set_num_threads(nb_coeurs);
	
	srand(time(NULL));

	/* Declaration des variables utilisees */
	double* vecteur;
	double* vecteur3;
	double* vecteur2;
	double s;
	int before;
	int after;
	vecteur=malloc(taille*sizeof(double));
	vecteur2=malloc(taille*sizeof(double));
	
	/* Q1. Remplissage aleatoire des vecteurs */
	printf("Creation de deux vecteurs\n");
	remplir(vecteur, taille);
	remplir(vecteur2, taille);
	printf("\n");
	
	/* Q2. Affichage des vecteurs */
	printf("Affichage des deux vecteurs\n");	
	// afficher(vecteur, taille);
	// afficher(vecteur2, taille);
	printf("\n");

	/* Q3. Addition de deux vecteurs */	
	printf("Addition des deux vecteurs\n");	
	before=(clock() * 1000) / CLOCKS_PER_SEC ;
	#pragma omp parallel
	{
		vecteur3 = ajouter(vecteur, vecteur2, taille);
	}
	after=(clock() * 1000) / CLOCKS_PER_SEC ;
	printf("Temps d'execution : %d msec\n", after-before);
	// afficher(vecteur3, taille);
	printf("\n");
	
	/* Q4. somme des cases d'un vecteur */
	printf("Somme d'un vecteurs\n");
	before=(clock() * 1000) / CLOCKS_PER_SEC ;
	#pragma omp parallel
	{	
		s=somme(vecteur, taille);
	}
	after=(clock() * 1000) / CLOCKS_PER_SEC ;
	printf("Temps d'execution : %d msec\n", after-before);
	printf("somme : %.2f\n", s);
	printf("\n");

	/* Multiplication d'un vecteur par un double */
	
	free(vecteur);
	free(vecteur2);
	free(vecteur3);
	return 0;
}
