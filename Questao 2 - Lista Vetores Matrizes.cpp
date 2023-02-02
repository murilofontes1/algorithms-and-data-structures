#include <stdlib.h>
#include <stdio.h>

int main(void){
	int linhas = 3;
	int colunas = 3;
    int ** matriz = (int**) malloc(linhas*sizeof(int));
    if(linhas == NULL){
    	printf("Memória insuficiente.\n");
    	exit(1);
	}
	int linha;
	for(linha = 0; linha < linhas; linha++){
		matriz[linha] = (int*) malloc(colunas*sizeof(int));
		if(colunas == NULL){
    		printf("Memória insuficiente.\n");
    		exit(1);
		}
	}
	
	int i, j;
	printf("Digite os valores para a matriz:\n");
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Digite os valores para a matriz:\n");
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("%d\t", matriz[i][j]);
		}
		printf(" \n");
	}
	
	for(i = 0; i < linhas; i++){
		free(matriz[i]);
	}
	free(matriz);
		
    return 0;
}
