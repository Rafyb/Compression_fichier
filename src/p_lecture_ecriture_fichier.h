#ifndef P_GENERATION_FICHIER_H_INCLUDED
#define P_GENERATION_FICHIER_H_INCLUDED
#include "p_bloc.h"

// Fonction permettant de g�n�rer un fichier de n nombre de bloc d'octets
void ecrire_fichier(char *Nom_Fichier, BLOC Mon_Bloc, char *mode);

void ecrire_Transformee(char *Nom_Fichier, char *Mon_Bloc, char *mode);

void ecrire_base(int **Mes_vecteurs);

// Fonction permettant de lire un fichier contenant n bloc d'octets
void lire_fichier(char *Nom_Fichier, BLOC Mon_Tableau, int idxBloc);

void lire_Transformee(char *Nom_Fichier, char *Mon_Tableau, int idxBloc);

void lire_fichier_base(char *Nom_Fichier, int **Mon_Tableau);

void afficher_base_orthonormee(int **Mes_Vecteurs, int bloc);

void afficher_transformee(char *Ma_Transformee);

// Fonction permettant d'afficher un tableau d'octets
void afficher_valeurs(BLOC Mon_Bloc);

#endif // P_GENERATION_FICHIER_H_INCLUDED
