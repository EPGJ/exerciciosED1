#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL* avl;
    int res,i;
    int num;
    
    avl = cria_ArvAVL();


    int N;

    scanf("%d", &N);

    clock_t t;
    t = clock();

    
 
    for(i=0;i<N;i++){
        scanf("%d", &num);
         //printf("asdsad1\n");
        res = insere_ArvAVL(avl,num);
         //printf("asdsad2\n");
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("\nAVL tree:\n");
    //emOrdem_ArvAVL(avl);
    printf("\n\n");


    printf("Carregar: %f sec\n", time_taken);

    // remove_ArvAVL(avl,6);
    // printf("\nAVL tree:\n");
    // emOrdem_ArvAVL(avl);
    // printf("\n\n");

    // remove_ArvAVL(avl,7);
    // printf("\nAVL tree:\n");
    // emOrdem_ArvAVL(avl);
    // printf("\n\n");

    // remove_ArvAVL(avl,4);
    // printf("\nAVL tree:\n");
    // emOrdem_ArvAVL(avl);
    // printf("\n\n");





    libera_ArvAVL(avl);


    return 0;
}
