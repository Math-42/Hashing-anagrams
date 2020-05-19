#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

unsigned long factorial(unsigned long f)
{
    if ( f == 0 ) 
        return 1;
    return(f * factorial(f - 1));
}

int comb(int n,int r){
	if(n ==0){
		return 0;
	}
	return (int) (factorial(n+r-1)/
	(factorial(n-1)*factorial((r))));
}

hash* criarHash(int n, int k){
    hash* newHash = (hash*)malloc(sizeof(hash));
    newHash->combinacoes = (int**)malloc((n+1)*sizeof(int*));
    for(int i=0; i<=n;i++){
        newHash->combinacoes[i] = (int*)malloc((k+1)*sizeof(int));
        for(int j=0;j<=k;j++){
            newHash->combinacoes[i][j] = comb(i,j);
        }
    }
    newHash->tabela = (no**)malloc(newHash->combinacoes[n][k] *sizeof(no*));
    newHash->tamanho = newHash->combinacoes[n][k];
    newHash->k = k;
    newHash->n = n;
    return newHash;
}

void sort(char arquivo[],char sorted[],int tamanhoMax){
    int* tempArray = (int*)malloc((tamanhoMax)*sizeof(int));
    int i=0;
    while(arquivo[i]!='\0'){
        tempArray[(int)(arquivo[i])-97]++;
        i++;
    }
    int j=0;
    for(int i=0;i<tamanhoMax;i++){
        if(tempArray[i]!=0){
            while(tempArray[i]!=0){
                sorted[j++] = i+97;
                tempArray[i]--;
            }
        }
    }
    free(tempArray);
}

int getKey(hash* tHash,char palavra[]){
    int tamanho = tHash->k;
    char* sorted = (char*)malloc((tamanho+1)*sizeof(char));
	int n = tHash->n;
	int k = tamanho;
    int c,key,last;
    c = key = last = 0;
	sort(palavra,sorted,n);
	for(int i=0;i<tamanho;i++){
		c = sorted[i]-97;
		key += tHash->combinacoes[n][k] - tHash->combinacoes[n-c+last][k];
		n-= c-last;
		k--;
		last = c;
	}
    free(sorted);
	return key;
}

int inserir(hash* tHash,char palavra[],int tamanhoPalavra){
    int key = getKey(tHash,palavra);
    no* elemento = (no*)malloc(sizeof(no));
    elemento->palavra = (char*)malloc(tamanhoPalavra * sizeof(char));
    int i=0;
    while (palavra[i] != '\0'){
        elemento->palavra[i] = palavra[i];
        i++;
    }
    if(tHash->tabela[key] == NULL){
        tHash->tabela[key] = elemento;
        return 1;
    }
    no* temp = tHash->tabela[key];
    while(temp->prox !=NULL){
        temp = temp->prox;
    }
    temp->prox = elemento;
    return 1;
}

void imprimir(hash* tHash){
    no* temp;
    int cont =0;
    for(int i=0; i<tHash->tamanho;i++){
        if(tHash->tabela[i] != NULL){
            cont++;
            temp = tHash->tabela[i];
            while(temp !=NULL){
                printf("%s ",temp->palavra);
                temp = temp->prox;
            }
            printf("\n");          
        }
    }
    printf("Grupos totais: %d\n",cont);
}

void liberarHash(hash* tHash){
    no* temp;
    no* temp2;
    for(int i=0; i<=tHash->n;i++){
        free(tHash->combinacoes[i]);
    }
    free(tHash->combinacoes);
    for(int i=0; i<tHash->tamanho;i++){
        if(tHash->tabela[i] != NULL){
            temp = tHash->tabela[i];
            while(temp !=NULL){
                temp2 = temp;
                temp = temp->prox;
                free(temp2->palavra);
                free(temp2);
            }    
        }
    }
    free(tHash->tabela);
    free(tHash);
}