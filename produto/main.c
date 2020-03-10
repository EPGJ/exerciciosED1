/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: 2018103403
 *
 * Created on 10 de Abril de 2019, 15:22
 */

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include"produto.h"

/*
 * 
 */
int main(int argc, char** argv) {
    setlocale(LC_ALL, "portuguese");

    tProduto produto;
    tLista lista;


    criaLista(&lista);

    if (estaVazia(&lista)) {
        printf("A lista está vazia!!\n");
    } else {
        printf("A lista não está vazia!!\n");
    }

    produto = criaProduto(1, "A\0", 1.0, 1);
    insereProduto(&lista, &produto);

    produto = criaProduto(2, "B\0", 2.0, 2);
    insereProduto(&lista, &produto);

    produto = criaProduto(3, "Cjgf\0", 1.7, 3);
    insereProduto(&lista, &produto);

    produto = criaProduto(4, "D\0", 7.0, 4);
    insereProduto(&lista, &produto);

    produto = criaProduto(5, "E\0", 5.0, 5);
    insereProduto(&lista, &produto);


    if (estaVazia(&lista)) {
        printf("A lista está vazia!!\n");
    } else {
        printf("A lista não está vazia!!\n");
    }

    printf("A quantidade de produtos na lista é %d\n", quantidadeProdutos(&lista));
    tProduto produtoMaisBarato = maisBarato(&lista);
     printf("O produto mais barato tem código %d e preço %f\n", produtoMaisBarato.codigo, produtoMaisBarato.preco);
    
    tProduto busca = buscaCodigo(&lista, 3);
    
    printf("\n\nProduto Buscado especificações:\nNome: %s\nCódigo: %d\nPreço: %f\nQtd em estoque: %d\n", busca.nome,busca.codigo,busca.preco,busca.quantidade);
    
    
    removerProduto(&lista,1);
   
    produtoMaisBarato = maisBarato(&lista);
    printf("O produto mais barato tem código %d e preço %f\n", produtoMaisBarato.codigo, produtoMaisBarato.preco);
    
    
    return 0;
}
