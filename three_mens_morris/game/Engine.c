/******************************************************

Autor: LUCAS CAMPOS TAVANO
Autor: EVERTON SANTOS BARRETO JUNIOR

******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Engine.h"
#include "Draw.h"
#include "AI.h"


int jogar(int tabuleiro[3][3], int dificuldade, int rodadas, int erro, int jogadores){
    int i1,j1,i2,j2;                                                //coordenadas
    if (erro == 0 && jogadores == 1){
        //system("cls");
        printf("Vez do computador!\n");
        aiPerformMove(tabuleiro,dificuldade,rodadas);               //AI joga
        rodadas++;
    }
    if (jogadores == 1)
        draw_tab(tabuleiro);                                            //DESENHA TABULEIRO
    if (checaVencedor(tabuleiro) != 0){                             //CHECA SE ALGUEM VENCEU
        if (checaVencedor(tabuleiro) == 1){
            printf("\nO jogador X venceu!!!\n");
            return 1;
        }
        if (checaVencedor(tabuleiro) == 2){
            printf("\nO jogador O venceu!!!\n");
            return 2;
        }
    }
    if (rodadas <= 6){                                              //COMEÇO DA PARTE QUE DEFINE COMO O JOGADOR AFETARÁ O TABULEIRO
        printaVez(rodadas, jogadores);
        printf("Coloque uma peca em local vazio do tabuleiro.\n");
        printf("Linha de destino: ");
        scanf("%d",&i1);
        printf("Coluna de destino: ");
        scanf("%d",&j1);

        if (haPeca(tabuleiro, i1, j1) == 1){
            printf("\n\nERRO: Local invalido, ja tem uma peca ali.\n");     //FERIFICA ERRO
            return jogar(tabuleiro, dificuldade, rodadas, 1, jogadores);
        }
        if (rodadas%2 == 0)
            tabuleiro[i1-1][j1-1] = 1;

        if ((rodadas%2) == 1 && jogadores == 2)
            tabuleiro[i1-1][j1-1] = 2;
    }
    else{
        printaVez(rodadas, jogadores);
        printf("Agora, mova suas pecas para casas adjascentes, colocando a posicao atual e a posicao de destino.\n");
        printf("Linha atual: ");
        scanf("%d",&i1);
        printf("Coluna atual: ");
        scanf("%d",&j1);

        if ( haPeca(tabuleiro, i1, j1) == 0){
            printf("\n\nERRO: Local invalido, nao ha peca na posicao que voce indicou.\n");     //FERIFICA ERRO
            return jogar(tabuleiro, dificuldade, rodadas, 1, jogadores);
        }
        if ((rodadas%2 == 0 && tabuleiro[i1-1][j1-1] == 2) || (rodadas%2 == 1 && tabuleiro[i1-1][j1-1] == 1)){
            printf("\n\nERRO: Que feio, nao tente mover a peca do seu adversario!\n");          //FERIFICA ERRO
            return jogar(tabuleiro, dificuldade, rodadas, 1, jogadores);
        }

        printf("Linha de destino: ");
        scanf("%d",&i2);
        printf("Coluna de destino: ");
        scanf("%d",&j2);

        if ( haPeca(tabuleiro, i2, j2) == 1){
            printf("\n\nERRO: Local invalido, ja tem uma peca ali.\n");                         //FERIFICA ERRO
            return jogar(tabuleiro, dificuldade, rodadas, 1, jogadores);
        }

        if ( !(((i2==(i1+1) || i2==(i1-1)) && j2 == j1) || ((j2==(j1+1) || j2==(j1-1)) && i2==i1))){
            printf("\n\nERRO: Local invalido, mova para uma casa adjascente.\n");               //FERIFICA ERRO
            return jogar(tabuleiro, dificuldade, rodadas, 1, jogadores);
        }

        if (rodadas%2 == 0){                    //JOGADOR 2 JOGA
            tabuleiro[i1-1][j1-1] = 0;
            tabuleiro[i2-1][j2-1] = 1;
        }

        if ((rodadas%2) == 1 && jogadores == 2){//JOGADOR 1 JOGA
            tabuleiro[i1-1][j1-1] = 0;
            tabuleiro[i2-1][j2-1] = 2;

        }
    }

    draw_tab(tabuleiro);                                           //DESENHA TABULEIRO
    if (checaVencedor(tabuleiro) != 0){                             //CHECA SE ALGUEM VENCEU
        if (checaVencedor(tabuleiro) == 1){
            printf("\nO jogador X venceu!!!\n");
            return 1;
        }
        if (checaVencedor(tabuleiro) == 2){
            printf("\nO jogador O venceu!!!\n");
            return 2;
        }
    }

    rodadas++;
    return jogar(tabuleiro, dificuldade,rodadas, 0, jogadores);
}

int** inicia(int dificuldade, int tabuleiro[3][3], int jogadores){
    zera_tab(tabuleiro);
    if (jogadores == 1)
        draw_tab(tabuleiro);
    return tabuleiro;
}

void zera_tab(int tabuleiro[3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            tabuleiro[i][j] = 0;
        }
    }
    return;
}

void printaVez(int rodadas, int jogadores){
    if (rodadas%2 == 0 && jogadores == 1){
        printf("Sua vez!\n");
    }
    if (rodadas%2 == 0 && jogadores == 2){
        printf("Vez do jogador 2\n");
    }
    if ((rodadas%2) == 1 && jogadores == 2){
        printf("Vez do jogador 1\n");
    }
}

int haPeca(int tabuleiro[3][3], int i1, int j1){
    if (tabuleiro[i1-1][j1-1] == 0)
        return 0;
    else
        return 1;
}

int checaVencedor(int tabuleiro[3][3]){
    if (tabuleiro[0][0] == 1){
        if (tabuleiro[1][0] == 1)
            if (tabuleiro[2][0] == 1)
                return 1;
        if (tabuleiro[0][1] == 1)
            if (tabuleiro[0][2] == 1)
                return 1;
    }
    if (tabuleiro[1][0] == 1){
        if (tabuleiro[1][1] == 1)
            if (tabuleiro[1][2] == 1)
                return 1;
    }
    if (tabuleiro[2][0] == 1){
        if (tabuleiro[2][1] == 1)
            if (tabuleiro[2][2] == 1)
                return 1;
    }
    if (tabuleiro[0][1] == 1){
        if (tabuleiro[1][1] == 1)
            if (tabuleiro[2][1] == 1)
                return 1;
    }
    if (tabuleiro[0][2] == 1){
        if (tabuleiro[1][2] == 1)
            if (tabuleiro[2][2] == 1)
                return 1;
    }
    if (tabuleiro[0][0] == 2){
        if (tabuleiro[1][0] == 2)
            if (tabuleiro[2][0] == 2)
                return 2;
        if (tabuleiro[0][1] == 2)
            if (tabuleiro[0][2] == 2)
                return 2;
    }
    if (tabuleiro[1][0] == 2){
        if (tabuleiro[1][1] == 2)
            if (tabuleiro[1][2] == 2)
                return 2;
    }
    if (tabuleiro[2][0] == 2){
        if (tabuleiro[2][1] == 2)
            if (tabuleiro[2][2] == 2)
                return 2;
    }
    if (tabuleiro[0][1] == 2){
        if (tabuleiro[1][1] == 2)
            if (tabuleiro[2][1] == 2)
                return 2;
    }
    if (tabuleiro[0][2] == 2){
        if (tabuleiro[1][2] == 2)
            if (tabuleiro[2][2] == 2)
                return 2;
    }
    return 0;
}
