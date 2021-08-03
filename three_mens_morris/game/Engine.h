#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#define ALTURA 3
#define LARGURA 3

typedef struct Engine
{

} Engine;

int** inicia(int dificuldade, int tabuleiro[3][3], int jogadores);
void zera_tab(int tabuleiro[3][3]);
int jogar(int tabuleiro[3][3], int dificuldade, int rodadas, int erro, int jogadores);
int checaVencedor(int tabuleiro[3][3]);
void printaVez(int rodadas, int jogadores);
int haPeca(int tabuleiro[3][3], int i1, int j1);

#endif
