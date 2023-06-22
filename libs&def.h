#ifndef LIBSDEF_H
#define LIBSDEF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


//Definições do baralho
typedef struct {
    int naipe;
    int valor;
    char naipec[2];
    char valorc[3];
} Carta;


//Definições da pilha
typedef int Apontador;
int qtdCartas=52;
typedef struct {
    Carta* baralho;
    Apontador topo;

} Pilha;

//Definições do jogo
typedef struct {
    int N_baralhos;
    int *excluidas;
    int numExcluidas;
    int coringa;
    int qtdCartas;
} InformacoesJogo;


//Estrutura de dados para o baralho
Carta geraCarta(Carta carta);
Pilha geraBaralho(int N_baralhos);
InformacoesJogo leEntrada();

//Estrutura de dados para a pilha
void criaPilhaVazia(Pilha* pilha,int N_baralhos);
void empilha(Pilha* pilha, Carta carta);
Carta desempilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
Carta topoPilha(Pilha* pilha);
int TamanhoPilha(Pilha pilha);

#endif // LIBSDEF_H