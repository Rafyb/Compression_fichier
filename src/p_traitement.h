#ifndef P_TRAITEMENT_H_INCLUDED
#define P_TRAITEMENT_H_INCLUDED
#include "p_bloc.h"

int** generer_base_orthonormee();

int produit_scalaire(BLOC Bloc, int* Mon_Vecteur);

void Transforme(BLOC Bloc, char* Transformee, int** Mes_Vecteurs);

void calcul_produit_inverse(char* Transformee, int** Mes_Vecteurs, BLOC Bloc);

void test_valeurs_transformee(BLOC origine,BLOC destination);


#endif // P_TRAITEMENT_H_INCLUDED
