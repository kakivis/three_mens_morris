/******************************************************

Autor: LUCAS CAMPOS TAVANO
Autor: EVERTON SANTOS BARRETO JUNIOR

******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Draw.h"
#define ALTURA 3
#define LARGURA 3

void draw_tab(int tabuleiro[3][3]){
    int i = 0, j = 0;
    for(i=0; i<3; i++){
        printf("\n*-*-*-*-*\n");
        for(j=0; j<3; j++){
            if(tabuleiro[i][j] == 1){
                printf("|X|");
            }
            if(tabuleiro[i][j] == 2){
                printf("|O|");
            }
            if(tabuleiro[i][j] == 0){
                printf("| |");
            }
        }
    }
    printf("\n*-*-*-*-*\n\n");
}
