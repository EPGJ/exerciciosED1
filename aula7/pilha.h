#ifndef PILHA_H
#define PILHA_H

typedef struct lista{
    float numero;
    struct lista *proximo;
}tLista;

typedef struct pilha{
    tLista* primeiro;
}tPilha;


void criaPilha(tPilha **pilha);
void push(tPilha **pilha, float valor);
float pop(tPilha **pilha);
int vazia(tPilha * pilha);
void destroiPilha(tPilha **pilha);
void empilhaOperando(tPilha **pilha, float valor);
void realizaContas(tPilha **pilha, char operador);




#endif