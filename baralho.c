#include "libs&def.h"

Pilha geraBaralho(int N_baralhos){
    Carta carta,carta1;
    Pilha baralhoNovo;
    InformacoesJogo jogo;
    criaPilhaVazia(&baralhoNovo, N_baralhos);
    jogo = leEntrada();
    for(int i=0;i<N_baralhos;i++){
        for (int j=0;j<4;j++){
            for(int k=0;k<13;k++){
                for (int l=0;l<jogo.numExcluidas;l++){
                    if (k==jogo.excluidas[l]){
                    qtdCartas=qtdCartas-4;
                    }
                else{
                    carta.valor=k+1;
                    carta.naipe=j;
                    carta1 = geraCarta(carta);
                    empilha(&baralhoNovo, carta1);
                   }
                }
            }
        }
    }
    return baralhoNovo;
}




//void separaCarta(int* cartasFora){

//}

Carta geraCarta(Carta carta){
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
        return carta;
    }