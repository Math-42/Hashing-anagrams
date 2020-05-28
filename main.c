#include <stdio.h>
#include <stdlib.h>
#include "sources/hash.h"

/*
    A função hash que gera a key indicando onde que cada palavra deve ser salva
    funciona utilizando a base numérica combinatorial, da seguinte forma:

    Dado uma combinação de n fatores tomados k a k, tem se formada então uma base numérica de 
    modo qualquer combinação possui um indice numérico e pode ser encontrada com base nesse indice, ou
    a partir do indice pode se encontrar a combinação.

    Ou seja, dada uma combinação é possivel encontrar o indice da mesma dentro do universo de todas as
    combinações possiveis do problema

    ex: 

    Tomando a=0,b=1,c=2 ... i=8,e utilizando 5 letras de cada vez temos:

    {a,a,a,a,a} => {0,0,0,0,0} <=> {0}
    {a,a,a,a,b} => {0,0,0,0,1} <=> {1}
    {a,a,a,a,c} => {0,0,0,0,2} <=> {2}
    {a,a,a,a,d} => {0,0,0,0,3} <=> {3}
    {a,a,a,a,e} => {0,0,0,0,4} <=> {4}
    {a,a,a,a,f} => {0,0,0,0,5} <=> {5}
    {a,a,a,a,g} => {0,0,0,0,6} <=> {6}
    {a,a,a,a,h} => {0,0,0,0,7} <=> {7}
    {a,a,a,a,i} => {0,0,0,0,8} <=> {8}
    {a,a,a,b,b} => {0,0,0,1,1} <=> {9}
    {a,a,a,b,c} => {0,0,0,1,2} <=> {10}
                ...
    {h,i,i,i,i} => {7,8,8,8,8} <=> {1285}
    {i,i,i,i,i} => {8,8,8,8,8} <=> {1286}

    note que anagramas quando são ordenados se tornam  exatamente iguais, logo dois anagramas mesmo que "distintos"
    retornarão a mesma chave, podendo então ter um hash estático aberto do tamanho exato de possibilidades de anagramas
    sem causar nenhum conflito indesejável e evitando a alocação de grandes vetores e inserção, podendo expandir para qualquer
    tamanho de string e conjunto de simbolos (no caso letras) mantendo complexidade de inserção O(c) de insersão sendo c o número 
    de caracteres nas strings.

    ref: https://en.wikipedia.org/wiki/Combinatorial_number_system
*/

int main(){
    char nomeArquivo[100];//variavel para salvar o nome do arquivo
    char palavra[6];//variavel para salvar cada palavra lida

    hash* newHash;//delaclara novo hash
    newHash = criarHash(9,5);//cria um hash do tipo palavras de tamanho 5 e 9 letras possiveis

    FILE* arq;
    scanf("%s",nomeArquivo);//Lê o nome do arquivo
    arq=fopen(nomeArquivo,"r");//abre o arquivo para leitura
    
    while(fscanf(arq,"%s",palavra)!= EOF){//percorre o arquivo lendo cada linha
        inserir(newHash,palavra,5);//insere cada palavra lida
    }
    
    imprimir(newHash);//imprime a tabela hash
    liberarHash(newHash);//libera toda memória que foi alocada
    return 0;
}