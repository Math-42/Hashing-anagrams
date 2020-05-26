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

hash* criarHash(int n, int k);//alloca o hash estático na memória
int getKey(hash* tHash,char palavra[]);//gera a chave a partir da palavra
int inserir(hash* tHash,char palavra[], int tamanhoPalavra);// insere uma nova palavra
void imprimir(hash* tHash);//imprime os elementos salvos
void liberarHash(hash* tHash);//limpa o hash e desaloca da memória
#endif
