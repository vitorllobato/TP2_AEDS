#include "libs&def.h"

InformacoesJogo leEntrada() {
    FILE *entrada;
    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    InformacoesJogo jogo;
    char *excluidas1 = (char *)malloc(20 * sizeof(char));
    char *token;

    fscanf(entrada, "%d", &(jogo.N_baralhos));
    fgetc(entrada);
    fgets(excluidas1, 20, entrada);
    excluidas1[strlen(excluidas1) - 1] = '\0';
    fgets(jogo.coringa, 3, entrada);
    Carta leituraCoringa = criaCartaCoringa(jogo.coringa);
    jogo.cartaCoringa = geraCarta(leituraCoringa);
    fscanf(entrada, "%d", &(jogo.qtdmao));
    fclose(entrada);

    token = strtok(excluidas1, ",");
    jogo.numExcluidas = 0;
    jogo.excluidas = NULL;

    while (token != NULL) {
        jogo.excluidas = (int *)realloc(jogo.excluidas, (jogo.numExcluidas + 1) * sizeof(int));
        if (jogo.excluidas == NULL) {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }
        jogo.excluidas[jogo.numExcluidas] = atoi(token);
        jogo.numExcluidas++;
        token = strtok(NULL, ",");
    }

    free(excluidas1);

    return jogo;
}

//Funções de jogo
Mao inicializaMao(InformacoesJogo jogo, Pilha *pilha) {
    Mao mao;
    mao.numCartas = jogo.qtdmao;
    mao.cartas = (Carta *)malloc(jogo.qtdmao * sizeof(Carta));
    for (int i = 0;i<jogo.qtdmao;i++){
        compraCarta(pilha, &mao, i);   
    }
    return mao;
}

Carta compraCarta(Pilha *pilha, Mao *mao, int posicao) {
    mao->cartas[posicao] = desempilha(pilha);
    Carta aux = mao->cartas[posicao];
    return aux;
    }

void descartaEcompraCarta(Pilha *descarte,Pilha *compra, Mao *mao, int posicao) {
    empilha(descarte, mao->cartas[posicao]);
    compraCarta(compra, mao, posicao);
}

void descartaCarta(Pilha *descarte, Mao *mao, int posicao) {
    empilha(descarte, mao->cartas[posicao]);
}

void pegaDescarte(Pilha *descarte, Mao *mao, int posicao) {
    Carta aux = mao->cartas[posicao];
    mao->cartas[posicao] = desempilha(descarte);
    empilha(descarte, aux);
}

void imprimeMao(Mao mao) {
    for (int i = 0; i < mao.numCartas; i++) {
        printf("Posição %d: %s %s \n",i, mao.cartas[i].valorc, mao.cartas[i].naipec);
    }
}

void topoDescarte(Pilha *descarte) {
    if(descarte->topo == -1)
        printf("Descarte vazio\n\n");
    else
    printf("%s %s\n\n", descarte->baralho[descarte->topo].valorc, descarte->baralho[descarte->topo].naipec);
    
}

int verificaVitoria(Mao mao, InformacoesJogo jogo) {
    int vitoria = 1;
    for (int i = 0; i < mao.numCartas; i++) {
        if (mao.cartas[i].valor != mao.cartas[0].valor) {
            if(mao.cartas[i].valor != jogo.cartaCoringa.valor || mao.cartas[i].naipe != jogo.cartaCoringa.naipe)
            vitoria = 0;
        }

    }
    return vitoria;
}