#include "libs&def.h"


//Gera um vetor com os numeros de cartas que serão usados, os valores 0 no vetor dem ser desconsiderados.
int* tamanhoBaralho(){
    int *formatobaralho;
    InformacoesJogo jogo;
    jogo = leEntrada();
    formatobaralho = (int *)malloc(13- jogo.numExcluidas * sizeof(int));
        for(int k=0;k<13;k++){
            int isExcluida = 0;
            for (int l=0;l<jogo.numExcluidas;l++){
                if (k+1==jogo.excluidas[l]){
                    qtdCartas=qtdCartas-4;
                    formatobaralho[k] = 0;
                    isExcluida = 1;
                    }
                }
            if (isExcluida == 0){
                formatobaralho[k] = k+1;   
            }
        }
    return formatobaralho;
}

//Gera o baralho e empilha as cartas.
Pilha geraBaralho(int N_baralhos){
    Carta carta,carta1;
    Pilha baralhoNovo;
    //InformacoesJogo jogo;
    int tamanhoMonte = 0;

    int *cartasPnaipe = tamanhoBaralho();
    criaPilhaVazia(&baralhoNovo, N_baralhos);
    //jogo = leEntrada();
    
    for(int i=0;i<N_baralhos;i++){
        for(int j=0;j<13;j++){
            if(cartasPnaipe[j]!=0){
                for(int k=0;k<4;k++){
                    tamanhoMonte++;
                    carta.valor = cartasPnaipe[j];
                    carta.naipe = k;
                    carta1 = geraCarta(carta);
                    //printf("%s%s\n",carta1.valorc,carta1.naipec);
                    empilha(&baralhoNovo,carta1);  
                }
            }
        }
    }
    embaralha(&baralhoNovo, tamanhoMonte);
    
    return baralhoNovo;
}

//Usa os valores inteiros para gerar as cartas em string.
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
            sprintf(carta.naipec,"C");
            break;
        case 1:
            sprintf(carta.naipec,"O");
            break;
        case 2:
            sprintf(carta.naipec,"P");
            break;
        case 3:
            sprintf(carta.naipec,"E");
            break;
        }
        return carta;
    }

//Embaralha a pilha criada com os baralhos.
void embaralha(Pilha* pilha,int tamanhoMonte){
    srand(time(NULL)); 
    
    for (int i = tamanhoMonte -1; i > 0; i--) {
        int j = rand() % (i+1);
        Carta temp = pilha->baralho[i];
        pilha->baralho[i] = pilha->baralho[j];
        pilha->baralho[j] = temp;
    }
}

//Lê o arquivo de entrada e descobre qual carta será o coringa.
Carta criaCartaCoringa(const char* coringa) {
    Carta carta;
    
    switch (coringa[0]) {
        case 'A':
            carta.valor = 1;
            break;
        case 'J':
            carta.valor = 11;
            break;
        case 'Q':
            carta.valor = 12;
            break;
        case 'K':
            carta.valor = 13;
            break;
        default:
            if (coringa[0] >= '1' && coringa[0] <= '9') {
                carta.valor = coringa[0] - '0';
            }
            break;
    }
    
    switch (coringa[1]) {
        case 'C':
            carta.naipe = 0;
            break;
        case 'O':
            carta.naipe = 1;
            break;
        case 'P':
            carta.naipe = 2;
            break;
        case 'E':
            carta.naipe = 3;
            break;
    }
    
    return carta;
}
