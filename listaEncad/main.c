#include"lista.h"


int main(){
    tLista *lista;

    criaLista(lista);
    lista = insereNaLista(lista,1);
    lista = insereNaLista(lista,2);
    imprimeLista(lista);
    liberaLista(lista);
    imprimeLista(lista);
    return 0;
}