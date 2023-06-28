#include "pilha.c"
#include "baralho.c"
#include "jogo.c"
#include "ordena.c"

int main(){
    InformacoesJogo jogo = leEntrada();
    Carta teste;
    Pilha compra;
    criaPilhaVazia(&compra, jogo.N_baralhos);
    compra = geraBaralho(jogo.N_baralhos);
    printf("Baralho criado\n");
    Pilha ordenada;
    criaPilhaVazia(&ordenada, jogo.N_baralhos);
    copiaPilha(&ordenada, &compra);
    printf("Baralho copiado\n");
    //quickSort(ordenada.baralho, 0, ordenada.tamanhoPilha-1);
    //insertionSort(ordenada.baralho, ordenada.tamanhoPilha);
    //selectionSort(ordenada.baralho, ordenada.tamanhoPilha);
    for(int i=0;i<(ordenada.tamanhoPilha);i++){
        teste = desempilha(&ordenada);
        printf("%s %s\n", teste.valorc, teste.naipec);
    }
    return 0;
}