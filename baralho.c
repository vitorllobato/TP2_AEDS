#include "baralho.h"

void geraBaralho(int N_baralhos){
    Carta carta;
    //Pilha baralhoNovo;
    //criaPilhaVazia(&baralhoNovo);
    for(int i=0;i<N_baralhos;i++){
        for (int j=0;j<4;j++){
            for(int k=0;k<13;k++){
                carta.valor=k+1;
                carta.naipe=j;
                geraCarta(carta);
                //empilha(&baralhoNovo,&carta);
            }
        }
    }
    //return baralhoNovo;
}

void geraCarta(Carta carta){
    switch(carta.valor){
        case 1:
            sprintf(carta.valorc,"A");
            break;
        case 11:
            sprintf(carta.valorc,"J");
            break;
        case 12:
            sprintf(carta.valorc,"Q");
            break;
        case 13:
            sprintf(carta.valorc,"K");
            break;
        default:
            sprintf(carta.valorc,"%d",carta.valor);
    }
    switch(carta.naipe){
        case 0:
            sprintf(carta.naipec,"P");
            break;
        case 1:
            sprintf(carta.naipec,"C");
            break;
        case 2:
            sprintf(carta.naipec,"O");
            break;
        case 3:
            sprintf(carta.naipec,"E");
            break;
        }
    printf("%s %s\n", carta.valorc,carta.naipec);
    }