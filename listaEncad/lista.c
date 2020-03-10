#include"lista.h"
#include<stdlib.h>
#include<stdio.h>


void criaLista(tLista *lista){
    lista = NULL;
}

tLista* insereNaLista(tLista *lista, int valor){
    tLista *p = (tLista*) malloc(sizeof(tLista));
    p->numero = valor;
    p->proximo= lista;
    return p;

}

void imprimeLista(tLista *lista){
    tLista *p;

    for(p=lista; p!=NULL; p = p->proximo){
        printf("(%d)", p->numero);
    }
}

void liberaLista(tLista *lista){
    tLista *p, *t;

    for(p=lista; p!=NULL; p = p->proximo){
        t=p;
        free(t);
    }

}