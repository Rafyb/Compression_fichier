#include <stdio.h>
#include <stdlib.h>
#include "p_traitement.h"

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
    for (int i=0;i<256;i++){
        printf("[%d] ",Mes_Vecteurs[bloc][i]);
    }
}

