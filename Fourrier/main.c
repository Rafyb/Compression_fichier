#include <stdio.h>
#include <stdlib.h>
#include "p_generation_fichier.h"

int main()
{
    //Créatino du tableau d'octets

    //unsigned int* Mon_Tableau = (unsigned int*)malloc(sizeof(char)* TAILLE_BLOC);
    unsigned char Mon_Tableau[TAILLE_BLOC];
    //generer_fichier() prend en paramètre le nombre de bloc que doit contenir le fichier de sortie
    generer_fichier(1);
    lire_fichier("fichier_binaire.bloc", &Mon_Tableau[0]);
    afficher_tableau(Mon_Tableau);
    return 0;
}
