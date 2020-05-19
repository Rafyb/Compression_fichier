#include "p_lecture_ecriture_fichier.h"
#include "p_bloc.h"
#include <stdio.h>
#include <stdlib.h>

void ecrire_fichier(char *Nom_Fichier, BLOC Mon_Bloc, char *mode) {
  // Ouverture
  FILE *Mon_Fichier;
  Mon_Fichier = fopen(Nom_Fichier, mode);
  if (Mon_Fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier\n");
  }
  // Ecriture
  fwrite(Mon_Bloc, sizeof(unsigned char), TAILLE_BLOC, Mon_Fichier);

  // Fermeture
  fclose(Mon_Fichier);
}

void ecrire_Transformee(char *Nom_Fichier, char *Mon_Bloc, char *mode) {
  // Ouverture
  FILE *Mon_Fichier;
  Mon_Fichier = fopen(Nom_Fichier, mode);
  if (Mon_Fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier\n");
  }
  // Ecriture
  fwrite(Mon_Bloc, sizeof(char), TAILLE_BLOC, Mon_Fichier);

  // Fermeture
  fclose(Mon_Fichier);
}

void lire_fichier(char *Nom_Fichier, BLOC Mon_Tableau, int idxBloc) {
  FILE *Mon_Fichier;
  int index;
  size_t mon_nb_lus;
  Mon_Fichier = fopen(Nom_Fichier, "rb");
  if (Mon_Fichier != NULL) {
    unsigned char bit;
    for (int i = 0; i < 256 * idxBloc; i++) {
      mon_nb_lus = fread(&bit, sizeof(unsigned char), 1, Mon_Fichier);
      if (mon_nb_lus == 0) {
        printf("Erreur lecture fichier\n");
        exit(1);
      }
    }
    mon_nb_lus = fread(&bit, sizeof(unsigned char), 1, Mon_Fichier);
    if (mon_nb_lus != 0) {
      Mon_Tableau[0] = bit;
      index = 1;
      while (index < TAILLE_BLOC) {
        mon_nb_lus = fread(&bit, sizeof(unsigned char), 1, Mon_Fichier);
        if (mon_nb_lus == 0) {
          printf("Erreur lecture fichier\n");
          exit(1);
        }
        Mon_Tableau[index] = bit;
        index++;
      }
    }
    fclose(Mon_Fichier);
  } else {
    printf("Impossible d'ouvrir le fichier %s\n", Nom_Fichier);
  }
}

void lire_Transformee(char *Nom_Fichier, char *Mon_Tableau, int idxBloc) {
  FILE *Mon_Fichier;
  int index;
  size_t mon_nb_lus;
  Mon_Fichier = fopen(Nom_Fichier, "rb");
  if (Mon_Fichier != NULL) {
    unsigned char bit;
    for (int i = 0; i < 256 * idxBloc; i++) {
      mon_nb_lus = fread(&bit, sizeof(unsigned char), 1, Mon_Fichier);
      if (mon_nb_lus == 0) {
        printf("Erreur lecture fichier\n");
        exit(1);
      }
    }
    mon_nb_lus = fread(&bit, sizeof(char), 1, Mon_Fichier);
    if (mon_nb_lus != 0) {
      Mon_Tableau[0] = bit;
      index = 1;
      while (index < TAILLE_BLOC) {
        mon_nb_lus = fread(&bit, sizeof(char), 1, Mon_Fichier);
        if (mon_nb_lus == 0) {
          printf("Erreur lecture fichier\n");
          exit(1);
        }
        Mon_Tableau[index] = bit;
        index++;
      }
    }
    fclose(Mon_Fichier);
  } else {
    printf("Impossible d'ouvrir le fichier %s\n", Nom_Fichier);
  }
}

void ecrire_base(int **Mes_vecteurs) {
  FILE *Mon_Fichier;
  Mon_Fichier = fopen("vecteurs.bloc", "w");
  if (Mon_Fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier\n");
  } else {
    for (int i = 0; i < 256; i++) {
      for (int j = 0; j < 256; j++) {
        // fwrite((Mes_vecteurs[i][j]), sizeof(int), 1, Mon_Fichier);
        fprintf(Mon_Fichier, "%d", Mes_vecteurs[i][j]);
        if (j < 256 - 1) {
          fprintf(Mon_Fichier, " ");
        }
        // fwrite(&delimiter, sizeof(char), 1, Mon_Fichier);
      }
      // fwrite(&saut, sizeof(char), 1, Mon_Fichier);
      if (i < 256 - 1) {
        fprintf(Mon_Fichier, "\n");
      }
    }
    fclose(Mon_Fichier);
  }
}

void afficher_base_orthonormee(int **Mes_Vecteurs, int bloc) {
  for (int i = 0; i < TAILLE_BLOC; i++) {
    printf("[%d] ", Mes_Vecteurs[bloc][i]);
  }
}

void afficher_transformee(char *Ma_Transformee) {
  printf("[%d] ", (unsigned char)Ma_Transformee[0]);
  for (int i = 1; i < TAILLE_BLOC; i++) {
    printf("[%d] ", Ma_Transformee[i]);
  }
  printf("\n");
}

void afficher_valeurs(BLOC Mon_Bloc) {
  for (int i = 0; i < TAILLE_BLOC; i++) {
    printf("[%d] ", Mon_Bloc[i]);
  }
  printf("\n");
}
