#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
    //Declaraçao e inicializacao de variáveis
        FILE* arq;
        char* palavra;
        //leitura dos valores que definem quantidade/tamanho de/das palavras
        char* nomeArq = (argc>1) ? argv[1]:"example.txt";//
        int tamanhoPalavras = (argc>2) ? atoi(argv[2]): 5;
        int qtdPalavras = (argc>3) ?  atoi(argv[3]): 100;
        palavra = (char*)malloc((tamanhoPalavras+1)*sizeof(char));
    //=========================
    //Execução
        srand(time(NULL));//Cria a seed para geração de números aleatórios
        arq = fopen(nomeArq,"w");//abre o arquivo
        fprintf(arq,"%d\n",qtdPalavras);//salva primeiramente a quantidade de palavras que serão geradas
        for(int i=0;i<qtdPalavras;i++){//repete "numero de palavras" vezes
            for(int j=0;j<tamanhoPalavras;j++){//cria cada letra da palavra
                palavra[j] = (char) (rand()%26+97);//gera um numero aleatorio entre 0 e 25, e soma a 97, 97 = 'a' em asc
            }
            fprintf(arq,"%s\n",palavra);//salva cada palavra
        }
    //=========================
    //Finalizacao
        fclose(arq);//fecha o arquivo
        free(palavra);//libera a palavra
        return 0;
    //=========================
}