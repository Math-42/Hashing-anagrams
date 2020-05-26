#include <stdio.h>
#include <stdlib.h>
#include "sources/hash.h"

/*
    A função hash que gera a key indicando onde que cada palavra deve ser salva
    funciona com base na base numérica combinatorial, que funciona da seguinte forma:

    Dado uma combinação de n fatores tomados k a k, tem se formada então uma base numérica de 
    forma que dado qualquer uma das possiveis combinações de forma ordenada ela possui um indice,
    e esse indice é possivel der ser encontrado a partir da combinação e vice versa.

    Ou seja, as possiveis combinações funciomam como uma base numérica, semelhante a qualquer outra como binário
    ou decimal.

    ex: 

    Tomando a=0,b=1,c=2 ... i=8,e utilizando 5 letras de cada vez temos:

    {0} <=> {0,0,0,0,0}
    {1} <=> {0,0,0,0,1}
    {2} <=> {0,0,0,0,2}
    {3} <=> {0,0,0,0,3}
    {4} <=> {0,0,0,0,4}
    {5} <=> {0,0,0,0,5}
    {6} <=> {0,0,0,0,6}
    {7} <=> {0,0,0,0,7}
    {8} <=> {0,0,0,0,8}
    {9} <=> {0,0,0,1,1}
    {10} <=> {0,0,0,1,2}
        ....
    {1285} <=> {7,8,8,8,8}
    {1286} <=> {8,8,8,8,8}

    note que como anagramas quando são ordenados se tornam iguais dois anagramas mesmo que distintos 
    retornaram a mesma chave, podendo então ter um hash estático do tamanho exato de possibilidades de anagramas
    sem causar nenhum conflito indesejável, podendo expandir para qualquer tamanho de string e conjunto de simbolos
    mantendo complexidade O(c) de insersão sendo c o número de caracteres nas strings.
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