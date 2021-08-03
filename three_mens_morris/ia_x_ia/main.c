/******************************************************

Autor: LUCAS CAMPOS TAVANO
Autor: EVERTON SANTOS BARRETO JUNIOR

******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Engine.h"
#include "AI.h"
#include "Draw.h"

void Tutorial(){
    printf("\nCada jogador possui tres pecas. O vencedor e o primeiro jogador a alinhar suas tres pecas na horizontal ou na vertical.\nO tabuleiro esta vazio para comecar o jogo, e os jogadores se revezam colocando suas peçcs nas interseccoes vazias. Uma vez que todas as pecas sao colocadas (assumindo que nao haja vencedor ate entao), o jogo continua com cada jogador movendo uma de suas pecas por turno. Uma peca pode se mover para qualquer ponto vago que esteja nas suas laterais (cima, baixo, direita, esquerda)\n\n\n");
}

int dificuldadeAI(){
    char leitura;
    printf("Escolha uma dificuldade de 1 a 3.\n");
    scanf("%s", &leitura);

    if (leitura == '1') return 1;
    if (leitura == '2') return 2;
    if (leitura== '3') return 3;

    else {
        printf("Dificuldade inválida.\n");
        return dificuldadeAI();
    }
}

int abertura(){
    char leitura;
    printf("Deseja jogar em quantas pessoas? (1 ou 2)\nCaso queira ver o tutorial digite \"T\".\n");
    scanf("%s", &leitura);

    if (leitura == 'T' || leitura == 't'){
        Tutorial();
        printf("Deseja jogar em quantas pessoas? (1 ou 2)\n");
        scanf("%s", &leitura);
    }

    if (leitura == '1') return 1;
    if (leitura == '2') return 2;

    else{
        printf("Numero de jogaderes inválido.\n");
        return abertura();
    }
}

int main(){
    int AI1 = 1, AI2 = 2;
    int tabuleiro[ALTURA][LARGURA];
    printf("\nOLA, SEJA BEM VINDO AO THREE MEN'S MORRIS\n\nAutores: Lucas Campos Tavano \n         Everton Santos Barrreto Junior \n\n");
    system("pause");
    printf("\nBOM JOGO!\n");
    inicia( 0 , tabuleiro);
    jogar( tabuleiro, 1, 1, 0, 1);
    return 0;
}
