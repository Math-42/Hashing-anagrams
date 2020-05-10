#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
    //Cria a seed para geração de números aleatórios
    srand(time(NULL));
    FILE* arq;
    char* palavra;
    char* nomeArq = (argc>1) ? argv[1]:"example.txt";
    int tamanhoPalavras = (argc>2) ? atoi(argv[2]): 5;
    int qtdPalavras = (argc>3) ?  atoi(argv[3]): 100;
    palavra = (char*)malloc((tamanhoPalavras+1)*sizeof(char));//Inicializa a varivel utilizada para salvar as palavras
    arq = fopen(nomeArq,"w");//abre o arquivo
    fprintf(arq,"%d\n",qtdPalavras);
    for(int i=0;i<qtdPalavras;i++){//repete "numero de palavras" vezes
        for(int j=0;j<tamanhoPalavras;j++){//cria cada letra da palavra
            palavra[j] = (char) (rand()%26+97);//gera um numero aleatorio entre 0 e 25, e soma a 97, 97 = 'a' em asc
        }
        fprintf(arq,"%s\n",palavra);
    }
    fclose(arq);
    free(palavra);
}