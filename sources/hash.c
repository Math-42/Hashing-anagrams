#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

unsigned long fatorial(unsigned long f){//calcula fatorial de um número
    if(f==0){ 
        return 1;
    }
    return(f*fatorial(f - 1));
}

int comb(int n,int r){//calcula a combinação de n tomado r a r
	if(n ==0){
		return 0;
	}
	return (int) (fatorial(n+r-1)/(fatorial(n-1)*fatorial((r))));
}

hash* criarHash(int n, int k){//cria o hash
    hash* newHash = (hash*)malloc(sizeof(hash));//aloca na memória
    newHash->combinacoes = (int**)malloc((n+1)*sizeof(int*));//aloca o espaço onde salvará todas as combinações
    for(int i=0; i<=n;i++){
        newHash->combinacoes[i] = (int*)malloc((k+1)*sizeof(int));
        for(int j=0;j<=k;j++){
            /*
                Como o algoritimo para gerar a key se baseia no calculo de combinações entre as letras
                e a posição onde ela está na palavra, é mais eficiente calcular todas as combinações possiveis 
                uma só vez do que calcular para cada palavra posteriormente pois calculos repetidos serão feitos 
                diversas vezes
            */
            newHash->combinacoes[i][j] = comb(i,j);//salva cada combinação possivel que será utilizada
        }
    }
    newHash->tabela = (no**)malloc(newHash->combinacoes[n][k] *sizeof(no*));//aloca a tabela hash
    newHash->tamanho = newHash->combinacoes[n][k];//salva o tamanho da tabela
    newHash->k = k;//salva o k, equivale ao tamanho das palavras que serão salvas
    newHash->n = n;//salva o n, equivalente a quantidade de letras que podem ser utilizadas para gerar as palavras
    return newHash;
}

void sort(char arquivo[],char sorted[],int tamanhoMax){//count sort modificado para ordenar as palavras
    int* tempArray = (int*)malloc((tamanhoMax)*sizeof(int));//aloca um array temp do tamanho das palavras que são salvas
    int i=0;
    while(arquivo[i]!='\0'){//percorre a string salvando cada caractere na sua posição ordenado, ex a=0, b=1 etc
        tempArray[(int)(arquivo[i])-97]++;
        i++;
    }
    int j=0;
    for(int i=0;i<tamanhoMax;i++){//percorre o array temporário inserindo os valores ordenadamente no array sorted
        if(tempArray[i]!=0){
            while(tempArray[i]!=0){
                sorted[j++] = i+97;
                tempArray[i]--;
            }
        }
    }
    free(tempArray);//libera o array temporário
}

int getKey(hash* tHash,char palavra[]){
    int tamanho = tHash->k;//pega o tamanho das palavras que estão sendo salvas nesse hash
    char* sorted = (char*)malloc((tamanho+1)*sizeof(char));//aloca um vetor de caracteres para salvar a string ordenada
	int n = tHash->n;//pega a quantidade de letras utilizadas para formar as palavras
	int k = tamanho;//variaveis auxiliares
    int c,key,last;
    c = key = last = 0;
	sort(palavra,sorted,n);//cria uma cópia ordenada da string
	for(int i=0;i<tamanho;i++){//percorre a string
		c = sorted[i]-97;//pega o elemento atual
        /*
            Aqui ao inves de calcular as combinações toda iteração ele apenas acesssa
            a matriz de combinações que foi criada na geração do hash, deixando o processo mais otimizado
        */
		key += tHash->combinacoes[n][k] - tHash->combinacoes[n-c+last][k];
		n-= c-last;
		k--;
		last = c;
	}
    free(sorted);//libera a cópia ordenada que foi utilizada apenas para gerar a chave
	return key;
}

int inserir(hash* tHash,char palavra[],int tamanhoPalavra){//insere uma nova palavra no hash
    int key = getKey(tHash,palavra);//pega a chave
    no* elemento = (no*)malloc(sizeof(no));//aloca um elemento para salvar a palavra
    elemento->palavra = (char*)malloc(tamanhoPalavra * sizeof(char));//alloca uma string para salvar a palvra
    int i=0;
    while (palavra[i] != '\0'){
        elemento->palavra[i] = palavra[i];//copia a palavra para dentro do elemento
        i++;
    }
    if(tHash->tabela[key] == NULL){//testa se naquela posição já existe um elemento salvo
        tHash->tabela[key] = elemento;//caso não exista esse passa a ser o primeiro elemento
        return 1;//finaliza
    }
    no* temp = tHash->tabela[key];
    while(temp->prox !=NULL){//caso não seja o primeiro elemento percorre até o final da lista encadeada para inserir
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
        free(tHash->combinacoes[i]);//libera a tabela de combinações
    }
    free(tHash->combinacoes);
    for(int i=0; i<tHash->tamanho;i++){//percorre a tabela hash
        if(tHash->tabela[i] != NULL){//vê se aquela posição foi usada
            temp = tHash->tabela[i];
            while(temp !=NULL){//caso tenha sido usada percorre a lista encadeada liberando cada elemento
                temp2 = temp;
                temp = temp->prox;
                free(temp2->palavra);
                free(temp2);
            }    
        }
    }
    free(tHash->tabela);//libera a tabela
    free(tHash);//libera a struct do hash
}