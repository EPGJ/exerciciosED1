#include"conjunto.h"
#include<stdlib.h>
#include<stdio.h>

void criarConjuntoVazio(tConjunto *conjunto){
    conjunto->primeiro = NULL;
    conjunto->ultimo = NULL;

}

tConjunto inserirConjunto(tConjunto *conjunto,int numero){
    tInteiro *novo = malloc(sizeof(tInteiro));
    
    if(conjunto->ultimo == NULL){
        conjunto->primeiro = novo;
        conjunto->ultimo = novo;
    }
    else{
        conjunto->ultimo->proximo = novo;
        conjunto->ultimo = conjunto->ultimo->proximo;
    }
    conjunto->ultimo->numero = numero;
    conjunto->ultimo->proximo = NULL;
    
  return conjunto;  
}
void imprimeConjunto(tConjunto *conjunto){
    tInteiro *p = conjunto->primeiro;
    
    while(p!=NULL){
        printf("(%d)", p->numero);
        p = p->proximo;
    }
}

void destroiConjunto(tConjunto *conjunto){
    tInteiro *p, *t = conjunto->primeiro;
    
    
    while(t!=NULL){
        p = t->proximo;
        free(t);
        t = p;  
        
    }
}