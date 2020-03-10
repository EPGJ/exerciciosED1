#ifndef LISTA_H
#define LIATA_H

typedef struct lista{
    int numero;
    struct lista *proximo;
}tLista;


// inicia lista com um endereço nulo;
void criaLista(tLista *lista);
tLista* insereNaLista(tLista *lista, int valor);
void imprimeLista(tLista *lista);
void liberaLista(tLista *lista);



#endif