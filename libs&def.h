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
    int tamanhoPilha;
} Pilha;

//Definições do jogo
typedef struct {
    int N_baralhos;
    int *excluidas;
    int numExcluidas;
    char coringa[3];
    Carta cartaCoringa;
    Carta cartaCoringaDefinitiva;
    int qtdmao;
} InformacoesJogo;

typedef struct {
    Carta *cartas;
    int numCartas;
} Mao;



//Estrutura de dados para o baralho
int* tamanhoBaralho();
Carta geraCarta(Carta carta);
Pilha geraBaralho(int N_baralhos);
void embaralha(Pilha* pilha, int tamanhoMonte);
Carta criaCartaCoringa(const char* coringa);


//Estrutura de dados para o jogo
InformacoesJogo leEntrada();



//Estrutura de dados para a pilha
void criaPilhaVazia(Pilha* pilha,int N_baralhos);
void empilha(Pilha* pilha, Carta carta);
Carta desempilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
Carta topoPilha(Pilha* pilha);
int TamanhoPilha(Pilha pilha);
void copiaPilha(Pilha* destino, Pilha* origem);

//Estrutura de dados para ordenação
void swap(Carta* a, Carta* b);
int partition(Carta arr[], int low, int high);
void quickSort(Carta arr[], int low, int high);

void selectionSort(Carta arr[], int n);
void insertionSort(Carta arr[], int n);


#endif // LIBSDEF_H