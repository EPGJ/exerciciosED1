#include"produto.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


tProduto criaProduto(int codigo, char *nome,float preco, int quantidade){
    tProduto produto;
    produto.codigo=codigo;
    produto.preco = preco;
    produto.quantidade = quantidade;
    strcpy(produto.nome, nome);
    
    return produto;
    
}
void criaLista(tLista *lista){
   lista->ultimo=0;
}

void insereProduto(tLista *lista, tProduto *produto){
    
    // verifica se a lista já está cheia
    if(!(lista->ultimo <= MAX_QTD_PRODUTOS)){
        printf("Não foi possível adicionar o produto, a lista já atingiu sua capacidade máxima");
        exit(1);
    }
    
    //verifica se produto já existe
    for(int i =0; i<=lista->ultimo;i++){
        if(produto->codigo == lista->produto[i].codigo){
            printf("Código já existente");
            exit(1);
        }
    }
    
    // insere na lista
    lista->produto[(lista->ultimo)] = *produto;     
    lista->ultimo++;
}
int estaVazia(tLista *lista){
    return !(lista->ultimo); // retorna 0 caso o indice do ultimo da lista seja maior que 0.
}
int quantidadeProdutos(tLista *lista){
    return lista->ultimo;
}
tProduto buscaCodigo(tLista *lista, int codigo){
    
    for(int i = 0; i<= lista->ultimo; i++){
        if(codigo == lista->produto[i].codigo){
            return lista->produto[i];
        }
    }
    
    printf("O código %d não está presente na lista", codigo);
    exit(1);
}
tProduto maisBarato(tLista *lista){
    float menorPreco = lista->produto[0].preco;
    int p=0;
    
    for(int i =0; i< lista->ultimo; i++){
        if(lista->produto[i].preco < menorPreco){
            menorPreco = lista->produto[i].preco;
            p = i;
        }
    }
    
    return lista->produto[p];
}

void removerProduto(tLista*lista, int codigo){
    int p = 0;
    for(int i=0; i<lista->ultimo;i++){
        if(lista->produto[i].codigo == codigo){
            p=i;
            break;
        }
    }
    if(p == lista->ultimo-1){
        lista->ultimo--;
    }
    
    for(int i=p;i<lista->ultimo-1;i++){
        lista->produto[i] = lista->produto[i+1];
    }
    
    
}