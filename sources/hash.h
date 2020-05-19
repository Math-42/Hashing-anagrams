#ifndef _HASH_H_
#define _HASH_H_


typedef struct no{
    char* palavra;
    struct no *prox;
}no;
typedef struct hash{
    int tamanho;
    int n;
    int k;
    int** combinacoes;
    no** tabela;
}hash;

hash* criarHash(int n, int k);
int getKey(hash* tHash,char palavra[]);
int inserir(hash* tHash,char palavra[], int tamanhoPalavra);
void imprimir(hash* tHash);
#endif
