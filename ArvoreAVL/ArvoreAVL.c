#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h" //inclui os Prot�tipos

struct NO{
    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;
    int tamesq;
};


int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}



//=================================
void RotacaoLL(ArvAVL *A){//LL
    //printf("RotacaoLL\n");
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;

    if(B->esq == NULL) B->tamesq =0;
    else{
        if(B->esq->esq == NULL &&B->esq->dir ==NULL) B->tamesq = 0;
        if(B->esq->esq != NULL &&B->esq->dir ==NULL) B->tamesq = 1;
        if(B->esq->esq == NULL &&B->esq->dir !=NULL) B->tamesq = 1;
        if(B->esq->esq != NULL &&B->esq->dir !=NULL) B->tamesq = 2;
    }


    *A = B;
}

void RotacaoRR(ArvAVL *A){//RR
    //printf("RotacaoRR\n");
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;

    if(B->esq == NULL) B->tamesq =0;
    else{
        if(B->esq->esq == NULL &&B->esq->dir ==NULL) B->tamesq = 0;
        if(B->esq->esq != NULL &&B->esq->dir ==NULL) B->tamesq = 1;
        if(B->esq->esq == NULL &&B->esq->dir !=NULL) B->tamesq = 1;
        if(B->esq->esq != NULL &&B->esq->dir !=NULL) B->tamesq = 2;
    }


    (*A) = B;
}

void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){//Arvore vazia ou no folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->tamesq = 0;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 2){
            if(fatorBalanceamento_NO(atual) >= 5){
                if(valor < (*raiz)->esq->info ){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
            
        }
    }else{
        if(valor > atual->info){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 2){
                if(fatorBalanceamento_NO(atual) >= 5){
                    if((*raiz)->dir->info < valor){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
          //  printf("Valor duplicado!!\n");
            return 0;
        }
    }


    if(atual->esq == NULL) atual->tamesq =0;
    else{
        if(atual->esq->esq == NULL &&atual->esq->dir ==NULL) atual->tamesq = 0;
        if(atual->esq->esq != NULL &&atual->esq->dir ==NULL) atual->tamesq = 1;
        if(atual->esq->esq == NULL &&atual->esq->dir !=NULL) atual->tamesq = 1;
        if(atual->esq->esq != NULL &&atual->esq->dir !=NULL) atual->tamesq = 2;
    }



    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}



