#include <stdio.h>
#include <stdlib.h>

#define size 1287

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

void countingSort(int arquivo[],int tamanho){
    int max, min;
    max = min = arquivo[0];
    for(int i=1;i<tamanho;i++){
        if(arquivo[i]>max){
            max = arquivo[i];
        }
        if(arquivo[i]<min){
            min = arquivo[i];
        }
    }
    int* tempArray = (int*)malloc((max-min+1)*sizeof(int));
    for(int i=0;i<tamanho;i++){
        tempArray[arquivo[i]-min]++;
    }
    int j=0;
    for(int i=0;i<max-min+1;i++){
        if(tempArray[i]!=0){
            while(tempArray[i]!=0){
                arquivo[j++] = i + min;
                tempArray[i]--;
            }
        }
    }
}

int getKey(int combinacao[]){
	int a[5];
	int n=9;
	int c=0;
	int k = 5;
	int idx = 0;
	int last=0;
	for(int i=0;i<5;i++){
		a[i]=combinacao[i];
	}
	countingSort(a, 5);
	for(int i=0;i<5;i++){
		c = a[i];
		idx+= comb(n,k)-comb(n-c+last,k);
		n-= c-last;
		k--;
		last = c;
	}
	return idx;
}

int main(void) {
  int soma[size];
  for(int i=0;i<size;i++){
    soma[i] = 0;
  }
  int cont = 0;
  int key = 0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        for(int l=0;l<3;l++){
          for(int m=0;m<3;m++){
			  if(cont>=0){
				int value[] = {i,j,k,l,m};
				key = getKey(value);
				soma[key]++;
				countingSort(value,5);
				printf("%4d) {%c,%c,%c,%c,%c} => {%c,%c,%c,%c,%c} => {%4d} = %d\n",
				cont,
				i+97,j+97,k+97,l+97,m+97,
				value[0]+97,value[1]+97,value[2]+97,value[3]+97,value[4]+97,
				key,
				soma[key]) ;
				cont++;
			  }
          }
        }
      }
    }
  }
  int max=0;
  int maxIndice=0;
  int min=soma[0];
  int minIndice=0;
  for(int i=0;i<size;i++){
    if(max<soma[i]){ 
      max = soma[i];
      maxIndice = i;
    }
    if((min>soma[i] || min==0) && soma[i]!=0){ 
      min = soma[i];
      minIndice = i;
    }
  }
  printf("Relatorio:\n");
  printf("  max = %d, index:%d\n",max,maxIndice);
  printf("  min = %d, index:%d\n",min,minIndice);
  printf("  diferenca = %d\n",max-min);
  printf("  media = %.3f\n",(float)(max+min)/2);
  printf("  size = %d\n",size);
  printf("  quantidade de palavras = %d\n",cont);
  printf("  fator de carga = %.3f\n",((float)cont)/size);
  return 0;
}
