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
    BLOC Mon_Bloc = (BLOC)malloc(sizeof(char) * TAILLE_BLOC);
    lire_fichier(argv[2], Mon_Bloc, index);
    // afficher_valeurs(Mon_Bloc);

    // On effectue la transformée
    char *Transformee = (char *)malloc(sizeof(char) * TAILLE_BLOC);
    Transforme(Mon_Bloc, Transformee, Mes_Vecteurs);
    // afficher_transformee(Transformee);
    if (index == 0)
      ecrire_Transformee(argv[3], Transformee, "wb");
    ecrire_Transformee(argv[3], Transformee, "ab");

    free(Mon_Bloc);
    free(Transformee);
    index++;
  }

  return 0;
}
