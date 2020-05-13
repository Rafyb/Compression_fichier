#ifndef P_TRAITEMENT_H_INCLUDED
#define P_TRAITEMENT_H_INCLUDED

int** generer_base_orthonormee();

unsigned char produit_scalaire(char ma_valeur);

unsigned char* calcul_produit_scalaire(char* Mon_Tableau);

void afficher_base_orthonormee(int** Mes_Vecteurs, int bloc);

#endif // P_TRAITEMENT_H_INCLUDED
