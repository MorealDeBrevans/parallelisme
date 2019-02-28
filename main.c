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
	
	
	srand(time(NULL));

	double* vecteur;
	vecteur=malloc(taille*sizeof(double));
	double* vecteur2;
	vecteur2=malloc(taille*sizeof(double));
	
	/* Q1. Remplissage aleatoire des vecteurs */
	remplir(vecteur, taille);
	remplir(vecteur2, taille);
	
	/* Q2. Affichage des vecteurs */	
	afficher(vecteur, taille);
	afficher(vecteur2, taille);

	/* Q3. Addition de deux vecteurs */	
	double * vecteur3 = ajouter(vecteur, vecteur2, taille);
	afficher(vecteur3, taille);
	
	//Q4. somme des cases d'un vecteur
	printf("%.2f\n", somme(vecteur, taille));
	
	free(vecteur);
	free(vecteur2);
	free(vecteur3);
	return 0;
}
