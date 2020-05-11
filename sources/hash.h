#ifndef _HASH_H_
#define _HASH_H_
#include "lista.h"
typedef struct hash{
    int tamanho;
    Lista* tabela;
}hash;

unsigned int gerarKey(char palavra[],int size);
hash* criarHash(int tamanho);
#endif
