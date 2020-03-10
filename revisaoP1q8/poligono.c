#include"poligono.h"
#include<stdio.h>
#include<stdlib.h>

void inserePonto(tPoligono *poligono, tPonto * ponto){
    tPontoPoligono *novo = malloc(sizeof(tPontoPoligono));
    
    if(poligono->primeiro == NULL){
        poligono->primeiro = novo;
        poligono->ultimo = novo;
    }
    else{
        poligono->ultimo->proximo = novo;
        poligono->ultimo = poligono->ultimo->proximo;
    }
    
    poligono->ultimo->ponto = *ponto;
    poligono->ultimo->proximo = NULL;
    
    
    
}
void criaPonto(int x, int y, tPonto *ponto){
    ponto->x = x;
    ponto->y = y;
}

void criaPoligono(tPoligono *poligono){
    poligono->primeiro = NULL;
    poligono->ultimo = NULL;
}

tPoligono *removePonto(tPoligono *poligono, tPonto *ponto){
    tPontoPoligono *anterior = NULL;
    tPontoPoligono *atual = poligono->primeiro;
    
    while(atual!=NULL && atual->ponto.x != ponto->x &&atual->ponto.y != ponto->y){
        anterior = atual;
        atual = atual->proximo;
    }
    
    if(atual == NULL){
        return poligono;
    }
    if(anterior == NULL){
        poligono->primeiro = atual->proximo;
    }
    else{
        anterior->proximo = atual->proximo;
    }
    
    free(atual);
    return poligono;    
}
void imprimePoligono(tPoligono *poligono){
    
    tPontoPoligono *p;
    
    for(p = poligono->primeiro; p !=NULL; p=p->proximo){
        printf("(%d,%d)\n", p->ponto.x,p->ponto.y);
    }
    
}
void destroiPoligono(tPoligono *poligono){
    
    tPontoPoligono *p;
    
    while(poligono->primeiro != NULL){
        p  = poligono->primeiro->proximo;
        free(poligono->primeiro);
        poligono->primeiro = p;
        
        
    }
    
    
}