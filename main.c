#include <stdio.h>
#include <stdlib.h>
#include "sources/hash.h"

int main(){
    char nomeArquivo[100];
    char palavra[6];

    hash* newHash;
    newHash = criarHash(9,5);

    FILE* arq;
    scanf("%s",nomeArquivo);
    arq=fopen(nomeArquivo,"r");
    
    while(fscanf(arq,"%s",palavra)!= EOF){
        inserir(newHash,palavra,5);
    }
    
    imprimir(newHash);
    liberarHash(newHash);
    return 0;
}