#include<stdio.h>
#include<stdlib.h>

int ** inicializaMatriz1(int **matriz1,int linhas,int colunas){   
    int count=0;
    
    for(int i = 0 ; i<linhas;i++){
        for(int j =0; j<colunas;j++){
            matriz1[i][j] = count;
            count++;
        }
    }
    return matriz1;
}

 
int ** criaMatriz1(int **matriz1,int linhas,int colunas){
    
    matriz1 = malloc(sizeof(int*)*linhas);
    
    for(int i = 0; i <linhas;i++){
        matriz1[i]  = malloc(sizeof(int)*colunas);
    }
    
    matriz1 =  inicializaMatriz1(matriz1,linhas,colunas);
    return matriz1;
    
}

int * matriz(int linhas, int colunas, int **matriz1){
    
    int *matriz2 = malloc(sizeof(int)*linhas*colunas);
    
    for(int i = 0 ; i<linhas;i++){
        for(int j =0; j<colunas;j++){
            matriz2[i*colunas+j] = matriz1[i][j];
        }
    }
    return matriz2;
}


void imprimeMatriz2(int *matriz2,int linhas,int colunas){
    
    for(int i = 0 ; i<linhas;i++){
        for(int j =0; j<colunas;j++){
            printf("(%d)", matriz2[i*colunas+j]);
        }
        printf("\n");
    }
    
}

void detroiMatriz1(int **matriz1,int linhas,int colunas){
    for(int i=0; i<linhas;i++){
        free(matriz1[i]);
    }
    free(matriz1);
}
void destroiMatriz2(int *matriz2){
    free(matriz2);
}


int main(){
    int **matriz1, linhas=3,colunas=3;
    int *matriz2;
    
    matriz1 = criaMatriz1(matriz1,linhas,colunas);
    matriz2 = matriz(linhas, colunas, matriz1);
    imprimeMatriz2(matriz2,linhas,colunas);
    detroiMatriz1(matriz1,linhas,colunas);
    destroiMatriz2(matriz2);
    
    
    
    
    
    return 0;
}