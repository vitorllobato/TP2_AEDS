#ifndef BARALHO_H
#define BARALHO_H

#include "libs&def.h"
#include "jogo.h"
#include "pilha.h"
#include "baralho.h"

//Definições do baralho
typedef struct {
    int naipe;
    int valor;
    char naipec[2];
    char valorc[3];
} Carta;

//Estrutura de dados para o baralho
void geraCarta(Carta carta);
Pilha geraBaralho(int N_baralhos);

#endif

