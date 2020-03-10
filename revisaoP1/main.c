/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: elias
 *
 * Created on 20 de Abril de 2019, 14:14
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*
 * 
 */

char * cifra_cesar(char * mensagem){
    char * nova = malloc(sizeof(char)*strlen(mensagem)+1);
    int i;
    
    strcpy(nova,mensagem);
    
    for( i =0; i < strlen(nova); i++){
        
        switch(nova[i]){
            case 'w':
                nova[i] = 'a';
                break;
                
            case 'y':
                nova[i] = 'b';
                break;
                
            case 'z':
                nova[i] = 'c';
                break;
            case 'W':
                nova[i] = 'A';
                break;
                
            case 'Y':
                nova[i] = 'B';
                break;
                
            case 'Z':
                nova[i] = 'C';
                break;
                
            default:
                if((nova[i]>='a' && nova[i]<='v')||(nova[i]>='A' && nova[i]<='V')){
                    nova[i]+= 3;
                }
            
        }
        
    }
    nova[i+1] = '\0';
    return nova;
}



int main(int argc, char** argv) {
    
    char * mensagem;
    
    mensagem = cifra_cesar("aaAAAz12");
    printf("%s", mensagem);
    
    
    free(mensagem);

    return (EXIT_SUCCESS);
}

