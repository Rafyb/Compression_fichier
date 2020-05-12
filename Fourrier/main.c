#include <stdio.h>
#include <stdlib.h>
#define TAILLE_BLOC 256

unsigned char* Mon_Bloc;
int Nb_Bloc = 100;
FILE* Mon_Fichier;

unsigned int int_to_int(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
}

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    Mon_Bloc = (unsigned char*)malloc(sizeof(char)* TAILLE_BLOC);
    Mon_Fichier = fopen("fichier_binaire.bloc", "wb");
    if(Mon_Fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier\n");
    }
    for(int i=1; i<=TAILLE_BLOC; i++){
        Mon_Bloc[i]=int_to_int(rand() % 255);
    }
    for(int i=1; i<=Nb_Bloc;i++){
       fwrite(Mon_Bloc, sizeof(unsigned char), TAILLE_BLOC, Mon_Fichier);
    }
    return 0;
}
