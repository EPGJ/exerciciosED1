/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   produto.h
 * Author: 2018103403
 *
 * Created on 10 de Abril de 2019, 15:23
 */

#ifndef PRODUTO_H
#define PRODUTO_H
#define MAX_QTD_PRODUTOS 6
#define MAX_CARACTERES_NOME 30  

typedef struct {
    int codigo;
    char nome[MAX_CARACTERES_NOME];
    float preco;
    int quantidade;
}tProduto;

typedef struct{
    tProduto produto[MAX_QTD_PRODUTOS];
    int ultimo;
}tLista;

tProduto criaProduto(int codigo, char *nome,float preco, int quantidade);
void criaLista(tLista *lista);
void insereProduto(tLista *lista, tProduto *produto);
int estaVazia(tLista *lista);
int quantidadeProdutos(tLista *lista);
tProduto buscaCodigo(tLista *lista, int codigo);
tProduto maisBarato(tLista *lista);
void removerProduto(tLista*lista, int codigo);





#endif /* PRODUTO_H */
