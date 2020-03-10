#ifndef POLIGONO_H
#define POLIGONO_H

typedef struct{
    int x,y;
}tPonto;

typedef struct pontoPoligono{
    tPonto ponto;
    struct pontoPoligono * proximo; 
}tPontoPoligono;

typedef struct {
    tPontoPoligono *primeiro, *ultimo;
}tPoligono;


void inserePonto(tPoligono *poligono, tPonto * ponto);
void criaPonto(int x, int y, tPonto *ponto);
void criaPoligono(tPoligono *poligono);
tPoligono *removePonto(tPoligono *poligono, tPonto *ponto);
void imprimePoligono(tPoligono *poligono);
void destroiPoligono(tPoligono *poligono);


#endif /* POLIGONO_H */

