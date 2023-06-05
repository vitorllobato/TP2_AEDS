#include "pilha.h"

void criaPilhaVazia(Pilha* pilha,int N_baralhos){
    pilha->topo = -1;
    pilha->baralho = (Carta*) malloc((N_baralhos*52)*sizeof(Carta));
}

void empilha(Pilha* pilha, Carta carta){
    pilha->topo++;
    pilha->baralho[pilha->topo] = carta;
}

Carta desempilha(Pilha* pilha){
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        exit(1);
        }
    
    Carta carta = pilha->baralho[pilha->topo];
    pilha->topo--;
    
    return carta;
}

int pilhaVazia(Pilha* pilha){
    return pilha->topo == -1;
}

Carta topoPilha(Pilha* pilha){
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        exit(1);
        }
    
    return pilha->baralho[pilha->topo];
}

//int TamanhoPilha(Pilha pilha)
