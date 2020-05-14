#include <stdio.h>
#include <stdlib.h>
#include "p_generation_fichier.h"
#include "p_traitement.h"
#include <time.h>

int main(){
    //srand((unsigned) time(NULL));
    srand(0);
    //Créatino du tableau d'octets

    //unsigned int* Mon_Tableau = (unsigned int*)malloc(sizeof(char)* TAILLE_BLOC);
    unsigned char Mon_Tableau[TAILLE_BLOC];
    //generer_fichier() prend en paramètre le nombre de bloc que doit contenir le fichier de sortie
    generer_fichier(1);
    lire_fichier("fichier_binaire.bloc", &Mon_Tableau[0]);
    afficher_vecteur(Mon_Tableau);
    printf("\n");
    int** Mes_Vecteurs = generer_base_orthonormee();
    ecrire_base(Mes_Vecteurs);
    //afficher_base_orthonormee(Mes_Vecteurs,2);
    char Transformee[TAILLE_BLOC];
    Transforme(Mon_Tableau,&Transformee[0],Mes_Vecteurs);
    afficher_transformee(Transformee);
    printf("\n\n");
    unsigned char Dtransformee[TAILLE_BLOC];
    calcul_produit_inverse(Transformee,Mes_Vecteurs,Dtransformee);
    afficher_vecteur(Dtransformee);
    printf("\n\n");
    test_valeurs_transformee(Mon_Tableau, Dtransformee);
    return 0;
}
