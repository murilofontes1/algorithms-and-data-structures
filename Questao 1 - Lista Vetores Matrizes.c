#include <stdlib.h>
#include <stdio.h>

int main(void){
    int tamanho = 10;
    int *vet = (int*) malloc (tamanho*sizeof(int));
    if(vet == NULL){
    	printf("Memória insuficiente.\n");
    	exit(1);
	}
    
    for (int i = 0; i < 10; i++){
        *(vet + i) = i;
    }
    for (int i = 0; i < 10; i++){
        printf("%d\t", vet[i]);
    }
    free(vet);
    return 0;
}
