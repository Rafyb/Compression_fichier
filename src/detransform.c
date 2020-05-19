#include "p_bloc.h"
#include "p_lecture_ecriture_fichier.h"
#include "p_traitement.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Erreur arguments incorrect\n");
    exit(-1);
  }
  // On génére la famille de vecteur
  int **Mes_Vecteurs = generer_base_orthonormee();

  int Nb_Bloc = atoi(argv[1]);
  int index = 0;
  while (index < Nb_Bloc) {
    // On lit ce fichier
    char *Mon_Bloc = (char *)malloc(sizeof(char) * TAILLE_BLOC);
    lire_Transformee(argv[2], Mon_Bloc, index);
    // afficher_transformee(Mon_Bloc);

    // On effectue la transformée
    BLOC DTransformee = (BLOC)malloc(sizeof(unsigned char) * TAILLE_BLOC);
    calcul_produit_inverse(Mon_Bloc, Mes_Vecteurs, DTransformee);
    // afficher_valeurs(DTransformee);
    if (index == 0)
      ecrire_fichier(argv[3], DTransformee, "wb");
    ecrire_fichier(argv[3], DTransformee, "ab");

    free(Mon_Bloc);
    free(DTransformee);
    index++;
  }
  free(Mes_Vecteurs);

  return 0;
}
