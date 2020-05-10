#include <stdlib.h>
#include <stdio.h>
#include "sources/hash.h"

int main(){
    char palavra[6];
    scanf("%s",palavra);
    printf("%d\n",gerarKey(palavra,5));
    return 0;
}