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
    printf("%d\n", jogo.N_baralhos);
    fgetc(entrada);
    fgets(excluidas1, 20, entrada);
    excluidas1[strlen(excluidas1) - 1] = '\0';
    printf("%s\n", excluidas1);
    fscanf(entrada, "%d", &(jogo.coringa));
    printf("%d\n", jogo.coringa);
    fscanf(entrada, "%d", &(jogo.qtdCartas));
    printf("%d\n", jogo.qtdCartas);
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

