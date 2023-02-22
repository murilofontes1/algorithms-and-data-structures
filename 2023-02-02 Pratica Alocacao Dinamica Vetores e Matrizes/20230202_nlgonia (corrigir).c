#include <stdio.h>
#include <stdlib.h>

int main(void){
    int m, n;
    int qtdCostas = 0;
    printf("Digite o numero de linhas e colunas da matriz:");
    scanf("%d %d", &m, &n);
    if(m < 1 || n > 1000){
        printf("Entrada invalida.");
    }
    else
    {
        char **matriz = (char**) malloc(m*sizeof(char*));
        if(matriz == NULL){
            exit(1);
        }

        for(int i = 0; i < m; i++){
            matriz[i] = (char*) malloc(n*sizeof(char*));
            if(matriz[i] == NULL){
                exit(1);
            }
        }

        printf("Preencha o mapa:\n");
        for(int i = 0; i < m; i++){
            scanf(" %[^\n]s", matriz[i]);
        }

        printf("Mapa:\n");
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                printf("%c\t", matriz[i][j]);
            }
            printf("\n");
        }

        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matriz[i][j] == '#'){
                    if(i == 0){
                        if(matriz[i][j+1] == '.' || matriz[i+1][j] == '.'){
                            qtdCostas++;
                        }
                    }

                    else if(i == m-1){
                        if(matriz[i][j+1] == '.' || matriz[i-1][j] == '.'){
                            qtdCostas++;
                        }
                    }

                    else{
                        if(matriz[i][j-1] == '.' || matriz[i][j+1] == '.' || matriz[i-1][j] == '.' || matriz[i+1][j] == '.'){
                            qtdCostas++;
                        }
                    }
                }
            }                
        }
        printf("%d", qtdCostas);
            for(int i = 0; i < m; i++){
                free(matriz[i]);
            }
        free(matriz);
    }
    return 0;
}
