#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
//#include "jogo.h"
//#include "pilha.h"
//#include "baralho.h"


//Definições do baralho
typedef struct {
    int naipe;
    int valor;
    char naipec[2];
    char valorc[3];
} Carta;


// Estrutura de dados para a pilha
typedef int Apontador;
//typedef struct Carta;

/*typedef struct {
    Carta* baralho;
    Apontador topo;
} Pilha;
*/
