#include "pilha.c"
#include "baralho.c"


int main(){
    int a=1;
    Pilha compra = geraBaralho(a);
    //printf("%d\n %s %s", compra.topo, compra.baralho[compra.topo].valorc, compra.baralho[compra.topo].naipec);
    topoPilha(&compra);
    return 0;
}