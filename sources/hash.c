#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

unsigned int gerarKey(char palavra[],int size){
    unsigned int key=1;
    for(int i=0;i<size;i++){
        key *= primos[(int) palavra[i] - 97];
    }
    return key;
}

hash* criarHash(int tamanho){
    hash* newHash = (hash*)malloc(sizeof(hash));
    newHash->tabela = (Lista*)malloc(tamanho*sizeof(Lista*));
    return newHash;
}