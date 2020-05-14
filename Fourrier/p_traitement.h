#ifndef P_TRAITEMENT_H_INCLUDED
#define P_TRAITEMENT_H_INCLUDED

int** generer_base_orthonormee();

int produit_scalaire(unsigned char* Bloc, int* Mon_Vecteur);

void Transforme(unsigned char* Bloc, char* Transformee, int** Mes_Vecteurs);

void afficher_base_orthonormee(int** Mes_Vecteurs, int bloc);

void calcul_produit_inverse(char* Transformee, int** Mes_Vecteurs, unsigned char* Bloc);

void test_valeurs_transformee(unsigned char* origine,unsigned char* destination);

void afficher_transformee(char* Ma_Transformee);

void afficher_vecteur(unsigned char* Mon_Vecteur);

#endif // P_TRAITEMENT_H_INCLUDED
