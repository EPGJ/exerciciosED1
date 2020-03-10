#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"


struct matriz {
    int nLinhas;
    int nColunas;
    int ** mat;
};

Matriz* inicializaMatriz(int nlinhas, int ncolunas){
        Matriz* mat;

        mat = (Matriz *) malloc(sizeof(Matriz*));
        mat->nLinhas=nlinhas;
        mat->nColunas=ncolunas;
        mat->mat = (int **)malloc(nlinhas*sizeof(int));

        int i =0;

        for(i=0;i<nlinhas;i++){
            mat->mat[i] = (int *) malloc(ncolunas*sizeof(int));
        }

    return mat;
}
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->mat[linha][coluna] = elem;
}
int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->mat[linha][coluna];
}
int recuperaNColunas (Matriz* mat){
    return mat->nColunas;
}
int recuperaNLinhas (Matriz* mat){
    return mat->nLinhas;
}
Matriz* transposta (Matriz* mat){

    Matriz *trp = inicializaMatriz(mat->nLinhas,mat->nColunas);

    for(int i =0; i <mat->nLinhas; i++){
        for(int j =0; j<mat->nColunas;j++){
            trp->mat[j][i] = mat->mat[i][j];
        }
    }

    return trp;
}
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    return NULL;
}
void imprimeMatriz(Matriz* mat){
        for(int i =0; i <mat->nLinhas;i++){
            for(int j =0; j< mat->nColunas;j++){
                printf("%d", mat->mat[i][j]);
            }
            printf("\n");
        }


        
       

}
void destroiMatriz(Matriz* mat){
    for(int i=0; i<mat->nLinhas; i++){
            free(mat->mat[i]);
        }
        free(mat->mat);
    free(mat);
}
void giraMatriz(Matriz* mat){
    Matriz *copia = inicializaMatriz(mat->nLinhas,mat->nColunas);

    for(int i =0; i <mat->nLinhas;i++){
            for(int j =0; j< mat->nColunas;j++){
               copia->mat[i][j] = mat->mat[i][j];
            }
    }

    for(int i =0; i <mat->nLinhas;i++){
            for(int j =0; j< mat->nColunas;j++){
                mat->mat[i][j] = copia->mat[mat->nColunas-1][i];
            }
    }
    free(copia);
}