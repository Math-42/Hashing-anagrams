#ifndef _HASH_H_
#define _HASH_H_
#include "lista.h"
typedef struct hash{
    int tamanho;
    Lista** tabela;
}hash;

typedef struct no{
    char* palavra;
    unsigned long int key;
}no;

unsigned long int gerarKey(char palavra[],int size);
hash* criarHash(int tamanho);
void inserir(hash* tempHash,char palavra[]);
#endif
