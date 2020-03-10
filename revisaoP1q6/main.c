#include<stdio.h>
#include<stdlib.h>

int * criaMatriz1(int *matriz1, int linhas,int colunas){
    int count=0;
        
    matriz1 = malloc(sizeof(int)*linhas*colunas);
    
    for(int i = 0; i <linhas;i++){
        for(int j=0;j <colunas;j++){
            matriz1[i*colunas+j] = count;
            count++;
        }
    }
    return matriz1;
    
}

void imprimeMatriz1(int *matriz1,int linhas,int colunas){
    for(int i = 0; i <linhas;i++){
        for(int j=0;j <colunas;j++){
            printf("(%d)", matriz1[i*colunas+j]);
        }
        printf("\n");
    }
    
}

void destroiMatriz2(int **matriz2,int linhas,int colunas ){
        
    for(int i=0;i<linhas;i++){
        free(matriz2[i]);
    }
    free(matriz2);
}
void destroiMatriz1(int *matriz1){
    free(matriz1);
}


void imprimeMatriz2(int **matriz2,int linhas, int colunas){
    
    for(int i = 0; i <linhas;i++){
        for(int j=0;j <colunas;j++){
            printf("(%d)", matriz2[i][j]);
        }
        printf("\n");
    }
    
}


int ** matriz(int linhas,int colunas, int * matriz1){
    
    int **matriz2 = malloc(sizeof(int*)*linhas);
    
    for(int i=0;i<linhas;i++){
        matriz2[i] = malloc(sizeof(int)*colunas);
    }
    
    for(int i = 0; i <linhas;i++){
        for(int j=0;j <colunas;j++){
            matriz2[i][j]= matriz1[i*colunas+j]; 
            
        }
    }
    return matriz2;
    
    
}


int main(){
    int *matriz1, linhas=3,colunas=3,count=0;
    int **matriz2;
    
    
    matriz1 = criaMatriz1(matriz1,linhas,colunas);
    imprimeMatriz1(matriz1,linhas,colunas);
    matriz2 = matriz(linhas, colunas, matriz1);
    printf("=============\n");
    imprimeMatriz2(matriz2,linhas,colunas);
    destroiMatriz1(matriz1);
    destroiMatriz2(matriz2,linhas,colunas);
    return 0;
}