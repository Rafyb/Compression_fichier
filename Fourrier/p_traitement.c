#include <stdio.h>
#include <stdlib.h>
#include "p_traitement.h"
#include "p_generation_fichier.h"

int** dedoubler(int** origin, int l){
    int** nouveau=(int**)malloc(sizeof(int*)*(l*2));
    for(int i = 0; i < l*2; i++){
        nouveau[i] = (int*)malloc(sizeof(int)*(l*2));
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            nouveau[2*i][j] = origin[i][j];
            nouveau[2*i][j+l] = origin[i][j];
            nouveau[2*i+1][j] = origin[i][j];
            nouveau[2*i+1][j+l] = -origin[i][j];
        }
    }
    free(origin);
    return nouveau;
}

int** generer_base_orthonormee(){
    int l = 1;
    int** Mon_Tableau = (int**)malloc(sizeof(int*) * l);
    /*
    for (int i=0; i<256;i++){
       Mon_Tableau[i] = (int*)malloc(sizeof(int)* 256);
    }*/
    Mon_Tableau[0] = (int*)malloc(sizeof(int) * l);
    Mon_Tableau[0][0]=1;

    while(l<256){
        Mon_Tableau = dedoubler(Mon_Tableau,l);
        l*=2;
    }
    return Mon_Tableau;
}

void afficher_base_orthonormee(int** Mes_Vecteurs, int bloc){
    for (int i=0;i<TAILLE_BLOC;i++){
        printf("[%d] ",Mes_Vecteurs[bloc][i]);
    }
}

void afficher_transformee(char* Ma_Transformee){
    printf("[%d] ",(unsigned char)Ma_Transformee[0]);
    for (int i=1;i<TAILLE_BLOC;i++){
        printf("[%d] ",Ma_Transformee[i]);
    }
    printf("\n");
}

void afficher_vecteur(unsigned char* Mon_Vecteur){
    for (int i=0;i<TAILLE_BLOC;i++){
        printf("[%d] ",Mon_Vecteur[i]);
    }
    printf("\n");
}

int produit_scalaire(unsigned char* Bloc, int* Mon_Vecteur){
    int res = 0;
    for(int i=0;i<TAILLE_BLOC;i++){
        res+= (int)Bloc[i] * Mon_Vecteur[i];
    }
    return res;
}

void Transforme(unsigned char* Bloc, char* Transformee, int** Mes_Vecteurs){
    Transformee[0]=(unsigned char)(produit_scalaire(Bloc,Mes_Vecteurs[0])/256);
    for(int i=1;i<TAILLE_BLOC;i++){
        Transformee[i]=(char)(produit_scalaire(Bloc,Mes_Vecteurs[i])/256);
    }
}

/*
B'[i] = somme_{j = 0}^{N-1} (T[j] * Base[j][i])

B'[0] = somme_{i = 0}^{N-1} (T[i] * Base[i][0])

B' - B est proche du vecteur nul.
*/

void calcul_produit_inverse(char* Transformee, int** Mes_Vecteurs,unsigned char* Bloc){
    int somme;
    for(int i=0;i<TAILLE_BLOC;i++){
        somme = (int)((unsigned char)Transformee[0]);
        for(int j=1;j<TAILLE_BLOC;j++){
            somme += (int) (Transformee[j]) * Mes_Vecteurs[j][i];
        }
        Bloc[i]= (unsigned char )somme;
    }
}

void test_valeurs_transformee(unsigned char* origine, unsigned char* destination){
    int res[TAILLE_BLOC];
    for(int i=0;i<TAILLE_BLOC;i++){
        res[i]=destination[i]-origine[i];
    }
    afficher_transformee(res);
}
