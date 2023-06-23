#include "pilha.c"
#include "baralho.c"
#include "jogo.c"

int main(){
    InformacoesJogo jogo = leEntrada();
    Carta teste;
    Pilha compra;
    criaPilhaVazia(&compra, jogo.N_baralhos);
    compra = geraBaralho(jogo.N_baralhos);

    for(int i=0;i<(qtdCartas * jogo.N_baralhos);i++){
        teste = desempilha(&compra);
        printf("%s %s\n", teste.valorc, teste.naipec);
    }
    return 0;
}