#include <stdio.h>
#include <stdlib.h>
#include "p_lecture_ecriture_fichier.h"
#include "p_traitement.h"
#include "p_bloc.h"
#include <time.h>

int main(){
    srand(0);
    int Nb_Bloc = 1;

    // On initialise un ficgier avec N bloc
    for(int i=0; i<Nb_Bloc;i++){
        BLOC Mon_Bloc = (BLOC)malloc(sizeof(char)* TAILLE_BLOC);
        initialiser_bloc(Mon_Bloc);
        ecrire_fichier(Mon_Bloc);
        free(Mon_Bloc);
    }

    // On lit ce fichier
    BLOC Mon_Tableau = (BLOC)malloc(sizeof(char)* TAILLE_BLOC);
    lire_fichier("fichier_binaire.bloc", Mon_Tableau);
    printf("Bloc d'origine :\n");
    afficher_valeurs(Mon_Tableau);

    // On génére la famille de vecteur
    int** Mes_Vecteurs = generer_base_orthonormee();
    // On la sauvegarde dans un fichier
    ecrire_base(Mes_Vecteurs);
    //afficher_base_orthonormee(Mes_Vecteurs,2);

    // On effectue la transformée
    char Transformee[TAILLE_BLOC];
    Transforme(Mon_Tableau,&Transformee[0],Mes_Vecteurs);
    printf("Resultat de la Transformée :\n");
    afficher_transformee(Transformee);

    // On effectue l'operation inverse
    BLOC Dtransformee = (BLOC)malloc(sizeof(char)* TAILLE_BLOC);
    calcul_produit_inverse(Transformee,Mes_Vecteurs,Dtransformee);
    printf("Bloc d'arrivée :\n");
    afficher_valeurs(Dtransformee);

    printf("Diférence entre origine et arrivée :\n");
    test_valeurs_transformee(Mon_Tableau, Dtransformee);

    free(Mon_Tableau);
    free(Dtransformee);

    return 0;
}