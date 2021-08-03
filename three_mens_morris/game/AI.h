/**
FONTES:

https://web.fe.up.pt/~eol/IA/IA0809/APONTAMENTOS/Alunos_MiniMax.pdf
https://pt.wikipedia.org/wiki/Minimax
https://www.youtube.com/watch?v=CwziaVrM_vc
*/

#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

typedef struct AImove {
    int x;
    int y;
    int xanterior;
    int yanterior;
    int score;
}AImove;

AImove aiGetBestMove(int tabuleiro[3][3], int dificuldade,int rodadasj, int rodadasa);
void aiPerformMove(int tabuleiro[3][3], int dificuldade, int rodadas);

#endif
