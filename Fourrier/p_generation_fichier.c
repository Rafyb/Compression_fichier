#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "p_generation_fichier.h"

unsigned int int_to_int(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
}

void generer_fichier(int Nb_Bloc){
    FILE* Mon_Fichier;
    Mon_Bloc = (unsigned char*)malloc(sizeof(char)* TAILLE_BLOC);
    Mon_Fichier = fopen("fichier_binaire.bloc", "wb");
    if(Mon_Fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier\n");
    }
    for(int i=0; i<TAILLE_BLOC; i++){
        //((rand()%(upper-lower+1))+lower)
        //unsigned int bval=((rand()%(122-97+1))+97);
        //unsigned char bval=((rand()%(127-1+1))+1);
        unsigned char bval=((rand()%(127-50+1))+50);
        //printf("Valeur aléatoire : %d | Caractère : %c | Octet : %d\n", bval,(char)int_to_int(bval),int_to_int(bval));
        Mon_Bloc[i]=bval;
    }
    //printf("Valeur de Mon_Bloc[1]: %d\n", Mon_Bloc[0]);
    for(int i=0; i<Nb_Bloc;i++){
       fwrite(Mon_Bloc, sizeof(unsigned char), TAILLE_BLOC, Mon_Fichier);
    }
    fclose(Mon_Fichier);
}

void lire_fichier(char* Nom_Fichier, unsigned char* Mon_Tableau){
    FILE* Mon_Fichier;
    int index;
    size_t mon_nb_lus;
    Mon_Fichier = fopen(Nom_Fichier, "rb");
    if (Mon_Fichier != NULL)
    {
        unsigned char bit;
        mon_nb_lus = fread(&bit, sizeof(unsigned char), 1, Mon_Fichier);
        //printf("nb lus : %d\n", mon_nb_lus);
        while(mon_nb_lus != 0){
            //printf(" un nouveau bloc\n");
            Mon_Tableau[0]=bit;
            index = 1;
            //printf("Char : %c\n",Mon_Tableau[index-1]);
            while(index < TAILLE_BLOC){
                mon_nb_lus = fread(&bit, sizeof(unsigned char), 1, Mon_Fichier);
                Mon_Tableau[index]=bit;
                index++;
                //printf("Char : %c\n",Mon_Tableau[index-1]);
            }
            mon_nb_lus = fread(&bit, sizeof(unsigned char), 1, Mon_Fichier);
        }
        fclose(Mon_Fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier %s\n",Nom_Fichier);
    }
}

void afficher_tableau(unsigned char* Mon_Tableau){
    for(int i=0;i<TAILLE_BLOC;i++){
        if((int)Mon_Tableau[i]<=122 && (int)Mon_Tableau[i]>=32){
            printf("[%c] ",Mon_Tableau[i]);
        }
        else{
            printf("[%d] ",Mon_Tableau[i]);
        }
    }
    printf("\n");
}

void ecrire_base(int** Mes_vecteurs){
    FILE* Mon_Fichier;
    Mon_Fichier = fopen("vecteurs.bloc", "w");
    if(Mon_Fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier\n");
    }
    else{
        for(int i=0; i<256;i++){
                for(int j=0;j<256;j++){
                    //fwrite((Mes_vecteurs[i][j]), sizeof(int), 1, Mon_Fichier);
                    fprintf(Mon_Fichier, "%d",Mes_vecteurs[i][j]);
                    if(j<256-1){
                        fprintf(Mon_Fichier, " ");
                    }
                    //fwrite(&delimiter, sizeof(char), 1, Mon_Fichier);
                }
                //fwrite(&saut, sizeof(char), 1, Mon_Fichier);
                if(i<256-1){
                    fprintf(Mon_Fichier, "\n");
                }
        }
        fclose(Mon_Fichier);
    }
}

