#include <stdio.h>
#include <stdlib.h>
#include"poligono.h"

int main(int argc, char** argv) {
    tPoligono poligono;
    tPonto ponto1, ponto2,ponto3,ponto4;
    
    criaPoligono(&poligono);
    criaPonto(1,1, &ponto1);
    criaPonto(2,2,&ponto2);
    criaPonto(1,3,&ponto3);
    criaPonto(10,6,&ponto4);
    
    inserePonto(&poligono, &ponto1);
    inserePonto(&poligono, &ponto2);
    inserePonto(&poligono, &ponto3);
    inserePonto(&poligono, &ponto4);
    
    imprimePoligono(&poligono);
    printf("=============\n");
    removePonto(&poligono, &ponto4);
    
    imprimePoligono(&poligono);
    
    destroiPoligono(&poligono);
    
    
    return 0;
}

