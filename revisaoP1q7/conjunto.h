/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conjunto.h
 * Author: elias
 *
 * Created on 20 de Abril de 2019, 16:13
 */

#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct inteiro{
    int numero;
    struct inteiro *proximo;
}tInteiro;

typedef struct{
    tInteiro *primeiro, *ultimo;
}tConjunto;


void criarConjuntoVazio(tConjunto *conjunto);
tConjunto inserirConjunto(tConjunto *conjunto,int numero);
void imprimeConjunto(tConjunto *conjunto);
void destroiConjunto(tConjunto *conjunto);





#endif /* CONJUNTO_H */

