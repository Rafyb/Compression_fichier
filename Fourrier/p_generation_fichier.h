#ifndef P_GENERATION_FICHIER_H_INCLUDED
#define P_GENERATION_FICHIER_H_INCLUDED
#define TAILLE_BLOC 256

unsigned char* Mon_Bloc;

//Fonction permettant de transformer un entier en octet (max 255)
unsigned int int_to_int(unsigned int k);
//Fonction permettant de générer un fichier de n nombre de bloc d'octets
void generer_fichier(int Nb_Bloc);
//Fonction permettant de lire un fichier contenant n bloc d'octets
void lire_fichier(char* Nom_Fichier, unsigned int* Mon_Tableau);
//Fonction permettant d'afficher un tableau d'octets
void afficher_tableau(unsigned int* Mon_Tableau);
#endif // P_GENERATION_FICHIER_H_INCLUDED
