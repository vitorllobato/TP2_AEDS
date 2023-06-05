#ifndef PILHA_H
#define PILHA_H

#include "libs&def.h"
#include "jogo.h"
#include "pilha.h"
#include "baralho.h"

// Estrutura de dados para a pilha
typedef int Apontador;
typedef struct c Carta;

typedef struct p {
    Carta* baralho;
    Apontador topo;
} Pilha;


// Protótipos das funções
void criaPilhaVazia(Pilha* pilha,int N_baralhos);
void empilha(Pilha* pilha, Carta carta);
Carta desempilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
Carta topoPilha(Pilha* pilha);
int TamanhoPilha(Pilha pilha);

#endif