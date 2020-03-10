#include<stdio.h>
#include"conjunto.h"


int main(){
    tConjunto conjunto;
    
    criarConjuntoVazio(&conjunto);
    conjunto = inserirConjunto(&conjunto,1);
    imprimeConjunto(&conjunto);
    destroiConjunto(&conjunto);
    
    return 0;
}