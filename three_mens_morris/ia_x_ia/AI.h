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
