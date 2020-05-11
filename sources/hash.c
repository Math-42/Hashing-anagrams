#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

unsigned long int gerarKey(char palavra[],int size){
    unsigned long int key=0;
    for(int i=0;i<size;i++){
        key += (int)(palavra[i]) - 96;
    }
    return key;
}

hash* criarHash(int tamanho){
    hash* newHash = (hash*)malloc(sizeof(hash));
    newHash->tabela = (Lista**)malloc(tamanho*sizeof(Lista*));
    newHash->tamanho = tamanho;
    return newHash;
}

void inserir(hash* tempHash,char palavra[]){
    unsigned long int x = gerarKey(palavra,strlen(palavra));
    printf("%ld\n",x-5);
    if(tempHash->tabela[x-5] == NULL){
        tempHash->tabela[x-5] = criarLista();
    }
    inserirElemento(tempHash->tabela[x-5],palavra);
}