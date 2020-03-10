#include"pilha.h"
#include<stdlib.h>
#include<stdio.h>

void criaPilha(tPilha **pilha){
    
    *pilha = malloc(sizeof(tPilha));
    (*pilha)->primeiro = NULL;

}
void push(tPilha **pilha, float valor){

    tLista *novo = malloc(sizeof(tLista));

    novo->numero =valor;
    novo->proximo = (*pilha)->primeiro;

    (*pilha)->primeiro = novo;


}
float pop(tPilha **pilha){

    tLista * t;
    float v;

    if(vazia(*pilha)){
        printf("A pilha esta vazio\n");
        exit(1);
    }

    t = (*pilha)->primeiro;
    v = t->numero;
    (*pilha)->primeiro = t->proximo;
    free(t);

}
int vazia(tPilha * pilha){
    return pilha->primeiro == NULL;
}
void destroiPilha(tPilha **pilha){
    tLista *p =(*pilha)->primeiro;

    while(p !=NULL){

        tLista * t = p->proximo;
        free(p);
        p = t;

    }

    free((*pilha));
}

void empilhaOperando(tPilha **pilha, float valor){

}
void realizaContas(tPilha **pilha, char operador){
    
}