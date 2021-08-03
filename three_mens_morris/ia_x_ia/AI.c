/******************************************************

Autor: LUCAS CAMPOS TAVANO
Autor: EVERTON SANTOS BARRETO JUNIOR

******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "AI.h"
#include "Engine.h"
#include "Draw.h"
#define ALTURA 3
#define LARGURA 3

AImove aiGetBestMove(int tabuleiro[LARGURA][ALTURA], int dificuldade,int rodadasj, int rodadasa){
        AImove moves[10];
        AImove bestmovescore;
        int i ,j ,k ,r; /** i & j - contadores para percorrer a matriz; k - tamanho do vetor; r - rodada que a IA está prevendo*/
        r = rodadasa;
        k=0;

        /** checa se alguém ganhou ou se chegou no limite máximo de previsoes*/
        if (checaVencedor(tabuleiro) == 1){
            bestmovescore.score = 10;
            //printf("retornou 1\n");
            return bestmovescore;
        }

        else if (checaVencedor(tabuleiro) == 2){
            bestmovescore.score = -10;
            //printf("retornou 2\n");
            return bestmovescore;
        }

        else if(rodadasa >= rodadasj + 3*dificuldade){
            bestmovescore.score = 0;
            //printf("retornou 3\n");
            return bestmovescore;
        }
        /** se a rodada atual for rodada de colocar peças, testa colocar peças em todos os espaços vazios*/
        if(r <= 6){
            for (i=0;i<3;i++){
                for (j=0;j<3;j++){
                    if (tabuleiro[i][j] == 0){
                        //printf("entrou1 rodada jogo %d rodada atual %d tabuleiro posicao [%d] [%d]\n",rodadasj,r,i,j);
                        AImove mov;
                        mov.x = i;
                        mov.y = j;
                        tabuleiro[mov.x][mov.y] = ((r%2)+1);
                        //draw_tab(tabuleiro);
                        r++;
                        mov.score = aiGetBestMove(tabuleiro,dificuldade,rodadasj,r).score;
                        r = rodadasa;
                        //printf("o score foi %d , no vet moves[%d] r vale %d enquanto rodadasa %d\n",mov.score, k,r,rodadasa);
                        moves[k] = mov;
                        k++;

                        tabuleiro[i][j] = 0;
                    }
                }
            }
        }
        /** se a rodada atual for para mover peças, em todas as suas peças, tenta movê-las para todas as posições adjacentes vazias*/
        if(r > 6){
            for (i=0;i<3;i++){
                for (j=0;j<3;j++){
                    if (tabuleiro[i][j] == ((r%2)+1)){
                        if(i+1 <= 2 && tabuleiro[i+1][j] == 0){
                            //printf("entrou2 rodada jogo %d rodada atual %d tabuleiro posicao [%d] [%d]\n",rodadasj,r,i,j);
                            AImove mov1;
                            mov1.x = i+1;
                            mov1.y = j;
                            mov1.xanterior = i;
                            mov1.yanterior = j;
                            tabuleiro[i][j] = 0;
                            tabuleiro[mov1.x][mov1.y] = ((r%2)+1);
                            //draw_tab(tabuleiro);
                            r++;
                            mov1.score = aiGetBestMove(tabuleiro,dificuldade,rodadasj,r).score;
                            r = rodadasa;
                            //printf("o score foi %d e r vale %d enquanto rodadasa %d\n",mov1.score,r,rodadasa);
                            moves[k] = mov1;
                            k++;

                            tabuleiro[mov1.x][mov1.y] = 0;
                            tabuleiro[i][j] = ((r%2)+1);
                            //draw_tab(tabuleiro);
                        }
                        if(i-1 >= 0 && tabuleiro[i-1][j] == 0){
                                //printf("entrou3 rodada jogo %d rodada atual %d tabuleiro posicao [%d] [%d]\n",rodadasj,r,i,j);
                            AImove mov2;
                            mov2.x = i-1;
                            mov2.y = j;
                            mov2.xanterior = i;
                            mov2.yanterior = j;
                            tabuleiro[i][j] = 0;
                            tabuleiro[mov2.x][mov2.y] = ((r%2)+1);
                            //draw_tab(tabuleiro);
                            r++;
                            mov2.score = aiGetBestMove(tabuleiro,dificuldade,rodadasj,r).score;
                            r = rodadasa;
                            //printf("o score foi %d e r vale %d enquanto rodadasa %d\n",mov2.score,r,rodadasa);
                            moves[k] = mov2;
                            k++;

                            tabuleiro[mov2.x][mov2.y] = 0;
                            tabuleiro[i][j] = ((r%2)+1);
                            //draw_tab(tabuleiro);
                        }
                        if(j+1 <= 2 && tabuleiro[i][j+1]== 0){
                                //printf("entrou4 rodada jogo %d rodada atual %d tabuleiro posicao [%d] [%d]\n",rodadasj,r,i,j);
                            AImove mov3;
                            mov3.x = i;
                            mov3.y = j+1;
                            mov3.xanterior = i;
                            mov3.yanterior = j;
                            tabuleiro[i][j] = 0;
                            tabuleiro[mov3.x][mov3.y] = ((r%2)+1);
                            //draw_tab(tabuleiro);
                            r++;
                            mov3.score = aiGetBestMove(tabuleiro,dificuldade,rodadasj,r).score;
                            r = rodadasa;
                            //printf("o score foi %d e r vale %d enquanto rodadasa %d\n",mov3.score,r,rodadasa);
                            moves[k] = mov3;
                            k++;

                            tabuleiro[mov3.x][mov3.y] = 0;
                            tabuleiro[i][j] = ((r%2)+1);
                            //draw_tab(tabuleiro);
                        }
                        if(j-1 >= 0 && tabuleiro[i][j-1]== 0){
                                //printf("entrou5 rodada jogo %d rodada atual %d tabuleiro posicao [%d] [%d]\n",rodadasj,r,i,j);
                            AImove mov4;
                            mov4.x = i;
                            mov4.y = j-1;
                            mov4.xanterior = i;
                            mov4.yanterior = j;
                            tabuleiro[i][j] = 0;
                            tabuleiro[mov4.x][mov4.y] = ((r%2)+1);
                            //draw_tab(tabuleiro);
                            r++;
                            mov4.score = aiGetBestMove(tabuleiro,dificuldade,rodadasj,r).score;
                            r = rodadasa;
                            //printf("o score foi %d e r vale %d enquanto rodadasa %d\n",mov4.score,r,rodadasa);
                            moves[k] = mov4;
                            k++;

                            tabuleiro[mov4.x][mov4.y] = 0;
                            tabuleiro[i][j] = ((r%2)+1);
                            //draw_tab(tabuleiro);
                        }
                    }
                }
            }
        }
        /** seleciona o melhor movimento do vetor de movimentos criado com os possiveis movimentos*/
        int bestmove = 0;
        if (r%2 == 1){
            int bestscore = 100000;
            //printf("estamos na rodada %d , é uma jogada de O e o tabuleiro esta assim:\n",r);
            //draw_tab(tabuleiro);
            for (i=0; i<k;i++){
                //printf("vetor movimentos na posicao %d vale %d e diz que o antigo xy %d %d vai mover para %d %d\n",i,moves[i].score,moves[i].xanterior, moves[i].yanterior,moves[i].x,moves[i].y);
                if (moves[i].score < bestscore){
                    bestmove = i;
                    bestscore = moves[i].score;
                }
            }
            //system("pause");
        }
        if (r%2 == 0){
            int bestscore = -100000;
            //printf("estamos na rodada %d , é uma jogada de X e o tabuleiro esta assim:\n",r);
            //draw_tab(tabuleiro);
            for (i=0; i<k;i++){
                //printf("vetor movimentos na posicao %d vale %d e diz que o antigo xy %d %d vai mover para %d %d\n",i,moves[i].score,moves[i].xanterior, moves[i].yanterior,moves[i].x,moves[i].y);
                if (moves[i].score > bestscore){
                    bestmove = i;
                    bestscore = moves[i].score;
                }
            }
        }
        //printf("retornou 4 com score de %d\n",moves[bestmove].score);
        return moves[bestmove];
}

void aiPerformMove(int tabuleiro[3][3], int dificuldade, int rodadas) {
    AImove bestMove = aiGetBestMove(tabuleiro,dificuldade, rodadas,rodadas);
    if (rodadas<=6)
        tabuleiro[bestMove.x][bestMove.y] = ((rodadas%2)+1);
    else if (rodadas>6){
        tabuleiro[bestMove.xanterior][bestMove.yanterior] = 0;
        tabuleiro[bestMove.x][bestMove.y] = ((rodadas%2)+1);
    }

    return;
}
