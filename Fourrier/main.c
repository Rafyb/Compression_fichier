#include <stdio.h>
#include <stdlib.h>
#define TAILLE_BLOC 256

unsigned char* Mon_Bloc;
int Nb_Bloc = 3;
FILE* Mon_Fichier;

int main()
{
    Mon_Bloc = (unsigned char*)malloc(sizeof(char)* TAILLE_BLOC);
    Mon_Fichier = fopen("fichier_binaire.bloc", "wb");
    if(Mon_Fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier\n");
    }
    for(int i=1; i<=Nb_Bloc;i++){
       fwrite(Mon_Bloc, sizeof(unsigned char), TAILLE_BLOC, Mon_Fichier);
    }
    return 0;
}
