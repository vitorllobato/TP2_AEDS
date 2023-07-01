#include "pilha.c"
#include "baralho.c"
#include "jogo.c"
#include "ordena.c"

int main(){
    InformacoesJogo jogo = leEntrada();
    Pilha compra, descarte;
    compra = geraBaralho(jogo.N_baralhos);
    criaPilhaVazia(&descarte, jogo.N_baralhos);
    printf("Selecione: \n1 - Jogar\n2 - Quick Sort\n3 - Selection Sort\n4 - Insertion Sort\n");
    int opcao;
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            printf("Bem vindo ao jogo de Pares!\nO jogo consiste em formar uma mão com cartas de valores iguais ou coringas.\n As ações no jogo são feitas por mumeros no teclado, portanto atenção quando for jogar.\n Boa sorte!\n ");
            Mao jogador1 = inicializaMao(jogo, &compra);
            Mao jogador2 = inicializaMao(jogo, &compra);
            int vez = 1;
            int vitoria = 0;
            int jogada;
            int cartaDescarte;

            while(vitoria != 1){
                printf("\nJogador %d, sua vez!\n", vez);
                printf("Carta do topo do descarte: \n");
                topoDescarte(&descarte);
                if(vez == 1){
                    imprimeMao(jogador1);
                    vitoria = verificaVitoria(jogador1, jogo);
                    if(vitoria == 1){
                        printf("Jogador 1 venceu!\n");
                        break;
                    }

                    printf("\nDigite 1 para comprar uma carta do baralho, 2 para pegar a carta do topo do descarte.\n");
                    scanf("%d", &jogada);
                    printf("Digite a posição da carta que deseja trocar:\n");
                    scanf("%d", &cartaDescarte);
                    switch (jogada){
                        case 1:
                            printf("Carta comprada: ");
                            topoPilha(&compra);
                            descartaEcompraCarta(&descarte, &compra, &jogador1, cartaDescarte);
                            break;
                        case 2:

                            pegaDescarte(&descarte, &jogador1, cartaDescarte);
                            break;
                        default:
                            printf("Jogada inválida!\n");
                            break;
                }
                vitoria = verificaVitoria(jogador1, jogo);
                    if(vitoria == 1){
                        printf("Jogador 1 venceu!\n");
                        break;
                    }
                vez = 2;
            }
                else{
                    imprimeMao(jogador2);
                    vitoria = verificaVitoria(jogador2, jogo);
                    if(vitoria == 1){
                        printf("Jogador 2 venceu!\n");
                        break;
                        }
                    printf("\nDigite 1 para comprar uma carta do baralho, 2 para pegar a carta do topo do descarte.\n");
                    scanf("%d", &jogada);
                    printf("Digite a posição da carta que deseja trocar:\n");
                    scanf("%d", &cartaDescarte);
                    switch (jogada){
                        case 1:
                            printf("Carta comprada: ");
                            topoPilha(&compra);
                            descartaEcompraCarta(&descarte, &compra, &jogador2, cartaDescarte);
                            break;
                        case 2:
                            pegaDescarte(&descarte, &jogador2, cartaDescarte);
                            break;
                        default:
                            printf("Jogada inválida!\n");
                            break;
                    }
                vitoria = verificaVitoria(jogador2, jogo);
                    if(vitoria == 1){
                        printf("Jogador 2 venceu!\n");
                        break;
                        }
                vez = 1;
                }  
            }
            break;
        int cont = 0;
        case 2:
            printf("Baralho desordenado:\n");
            clock_t inicio = clock();
            quickSort(compra.baralho, 0, compra.tamanhoPilha-1);
            clock_t fim = clock();
            double tempo_segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo total de execução %.5f \n", tempo_segundos );
            FILE *arq;
            arq = fopen("quickSort.txt", "w");
            
            for(int i = 0; i < compra.tamanhoPilha; i++){
                fprintf(arq, "%s %s   ", compra.baralho[i].valorc , compra.baralho[i].naipec);
                cont++;
                if(cont == jogo.N_baralhos){
                    fprintf(arq, "\n");
                    cont = 0;
                }
            }
            fclose(arq);
            printf("Baralho ordenado:\n");
            break;

        case 3:
            printf("Baralho desordenado:\n");
            inicio = clock();
            selectionSort(compra.baralho, compra.tamanhoPilha);
            fim = clock();
            tempo_segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo total de execução %.5f \n", tempo_segundos );
            arq = fopen("SelectionSort.txt", "w");
            for(int i = 0; i < compra.tamanhoPilha; i++){
                fprintf(arq, "%s %s   ", compra.baralho[i].valorc , compra.baralho[i].naipec);
                cont++;
                if(cont == jogo.N_baralhos){
                    fprintf(arq, "\n");
                    cont = 0;
                }
            }
            fclose(arq);
            printf("Baralho ordenado:\n");
            break;

        case 4:
            printf("Baralho desordenado:\n");
            inicio = clock();  
            insertionSort(compra.baralho, compra.tamanhoPilha);
            fim = clock();
            tempo_segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo total de execução %.5f \n", tempo_segundos );
            arq = fopen("InsertionSort.txt", "w");
            for(int i = 0; i < compra.tamanhoPilha; i++){
                fprintf(arq, "%s %s   ", compra.baralho[i].valorc , compra.baralho[i].naipec);
                cont++;
                if(cont == jogo.N_baralhos){
                    fprintf(arq, "\n");
                    cont = 0;
                }
            }
            fclose(arq);
            printf("Baralho ordenado:\n");
            break;
    }
    return 0;
}