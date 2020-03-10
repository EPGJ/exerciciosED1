#ifndef LISTAARR_H_
#define LISTAARR_H_

#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 1000

typedef int Posicao;

typedef struct
{
  int Chave;

} tItem;

typedef struct
{
  tItem Item[MAXTAM];
  Posicao  Ultimo;
} tLista;

/* Faz a lista ficar vazia */
void FLVazia(tLista *Lista);

/*Verifica se a lista est� vazia*/
int Vazia(tLista *Lista);

/* Insere x ap�s o �ltimo elemento da lista */
void Insere(tItem *item, tLista *Lista);

/*Op��o que n�o modifica o lista.h */
void Retira(Posicao p, tLista *Lista, tItem *Item);
/*Imprime a lista */
void Imprime(tLista *Lista);

/*Quantidade de elementos na lista*/
int Quantidade(tLista *Lista);

/*Copia uma lista */
void copiaLista(tLista *ListaOrigem, tLista *ListaDestino);

/*Copia uma lista */
void partirLista(int p, tLista *ListaOrigem, tLista *ListaDestino);

tItem Recupera(Posicao p, tLista *Lista);

#endif /* LISTAARR_H_ */
