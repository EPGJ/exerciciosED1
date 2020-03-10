#include"listahet.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


ListaHet* cria (){
    return NULL;
}
Cliente* cria_cliente (char* nome, int id){
    
    Cliente * cliente = malloc(sizeof(Cliente));
    
    cliente->nome = (char *) malloc(sizeof(char)* strlen(nome)+1 );
    strcpy(cliente->nome, nome);
    cliente->id = id;
    
    return cliente;
    
}
Movel* cria_movel (int placa, int ano, float valor){
    Movel * movel = malloc(sizeof(Movel));
    movel->ano = ano;
    movel->placa = placa;
    movel->valor = valor;
    
    return movel;
}
Imovel* cria_imovel (int id, int ano, float valor){
    
    Imovel *imovel= malloc(sizeof(Imovel)); ;
    
    imovel->ano = ano;
    imovel->identificador = id;
    imovel->valor = valor;
    
    return imovel;
    
}
ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item){
    
    ListaHet * novo = malloc(sizeof(ListaHet));
    
    novo->dono = dono;
    novo->item = item;
    novo->idItem = 1;
    novo->proximo = lista;
    
    return novo;
}
ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item){
    
    ListaHet * novo = malloc(sizeof(ListaHet));
    
    
    novo->dono = dono;
    novo->item = item;
    novo->idItem = 2;
    novo->proximo = lista;
    
    return novo;  
}

void imprimeCliente(Cliente * cliente){
    printf("\nCliente:\nNome: %s\nIdentificador: %d\n", cliente->nome,cliente->id);
}


void imprimeMovel(Movel *movel){
    printf("\nMovel:\nPlaca: %d\nAno: %d\nValor: %f\n", movel->placa,movel->ano,movel->valor);
}
void imprimeImovel(Imovel *imovel){
    printf("\nImovel:\nIdentificador: %d\nAno: %d\nValor: %f\n", imovel->identificador,imovel->ano,imovel->valor);
}



void imprimeItem(void * item, int identificador){
    switch(identificador){
        case 1:
            imprimeMovel(item);
            break;
        case 2:
            imprimeImovel(item);
            break;
    }
}

void imprime (ListaHet* lista){
    
    ListaHet * p = lista;
    
    for(p = lista; p!= NULL; p= p->proximo){
        printf("=======================");
        imprimeCliente(p->dono);
        imprimeItem(p->item, p->idItem);
    }
    
    
}


ListaHet* retira_cliente (ListaHet* lista, int id_cliente){
    
    
    
    
}

float calculaValorMovel(Movel *movel, float taxa){
    return (movel->valor *taxa);
};
float calculaValorImovel(Imovel *imovel, float taxa){
    return (imovel->valor *taxa);
};

float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel){
    
    ListaHet * p;
    float valor=0;
    
    for(p=lista; p!=NULL;p = p->proximo){
        if(p->dono == dono){
            if(p->idItem == 1){
                valor += calculaValorMovel(p->item, taxa_movel); 
            }
            if(p->idItem == 2){
                valor+= calculaValorImovel(p->item, taxa_imovel);
            }
            
        }
    }
    return valor;
    
}
