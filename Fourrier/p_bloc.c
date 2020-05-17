#include "p_bloc.h"
#include <stdlib.h>

void initialiser_bloc( BLOC Mon_Bloc ){
    for(int i=0; i<TAILLE_BLOC; i++){
        unsigned char bval=((rand()%(127-50+1))+50);
        Mon_Bloc[i]=bval;
    }
}


