#ifndef P_GENERATION_FICHIER_H_INCLUDED
#define P_GENERATION_FICHIER_H_INCLUDED
#define TAILLE_BLOC 256

unsigned char* Mon_Bloc;

//Fonction permettant de transformer un entier en octet (max 255)
unsigned int int_to_int(unsigned int k);
//Fonction permettant de g�n�rer un fichier de n nombre de bloc d'octets
void generer_fichier(int Nb_Bloc);

#endif // P_GENERATION_FICHIER_H_INCLUDED
