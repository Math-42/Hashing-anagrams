#include <stdlib.h>
#include <stdio.h>
#include "sources/hash.h"

int main(){
    int qtdPalavras;
    FILE* arq;
    hash* anagramHash;
    //scanf("%d",&qtdPalavras);
    char palavra[] = "zzazz";
    anagramHash = criarHash(126);
    inserir(anagramHash,palavra);
    return 0;
}