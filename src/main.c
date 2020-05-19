#include "p_bloc.h"
#include "p_lecture_ecriture_fichier.h"
#include "p_traitement.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// CODE DE TEST
int main(int argc, char *argv[]) {
  srand(0);
  if (argc < 2) {
    printf("Veuillez entre un nombre de bloc à générer\n");
    exit(-1);
  }
  int Nb_Bloc = atoi(argv[1]);
  // int Nb_Bloc = argv[1];
  int index = 0;

  // On initialise un ficgier avec N bloc
  for (int i = 0; i < Nb_Bloc; i++) {
    BLOC Mon_Bloc = (BLOC)malloc(sizeof(char) * TAILLE_BLOC);
    initialiser_bloc(Mon_Bloc);
    if (i == 0)
      ecrire_fichier("fichier_binaire.bloc", Mon_Bloc, "wb");
    else
      ecrire_fichier("fichier_binaire.bloc", Mon_Bloc, "ab");
    free(Mon_Bloc);
  }

  // On génére la famille de vecteur
  int **Mes_Vecteurs = generer_base_orthonormee();
  // On la sauvegarde dans un fichier
  ecrire_base(Mes_Vecteurs);
  lire_fichier_base("vecteurs.bloc", Mes_Vecteurs);

  while (index < Nb_Bloc) {
    // On lit ce fichier
    BLOC Mon_Tableau = (BLOC)malloc(sizeof(char) * TAILLE_BLOC);
    lire_fichier("fichier_binaire.bloc", Mon_Tableau, index);
    printf("Bloc d'origine :\n");
    afficher_valeurs(Mon_Tableau);

    // afficher_base_orthonormee(Mes_Vecteurs,2);

    // On effectue la transformée
    char Transformee[TAILLE_BLOC];
    Transforme(Mon_Tableau, &Transformee[0], Mes_Vecteurs);
    // printf("Resultat de la Transformée :\n");
    // afficher_transformee(Transformee);

    // On effectue l'operation inverse
    BLOC Dtransformee = (BLOC)malloc(sizeof(char) * TAILLE_BLOC);
    calcul_produit_inverse(Transformee, Mes_Vecteurs, Dtransformee);
    // printf("Bloc d'arrivée :\n");
    // afficher_valeurs(Dtransformee);

    printf("Diférence entre origine et arrivée :\n");
    test_valeurs_transformee(Mon_Tableau, Dtransformee);

    free(Mon_Tableau);
    free(Dtransformee);
    index++;
  }
  for (int i = 0; i < 256; i++) {
    free(Mes_Vecteurs[i]);
  }
  free(Mes_Vecteurs);

  return 0;
}
