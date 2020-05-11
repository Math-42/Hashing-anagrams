#include <stdlib.h>
#include <stdio.h>
#include "sources/hash.h"

int main(){
    char palavra[6];
    int qtdPalavras;
    hash* anagramHash;
    scanf("%d",&qtdPalavras);
    anagramHash = criarHash(qtdPalavras);
    return 0;
}