#include <stdio.h>
#include <stdlib.h>

int main(void){
    // inicializaçao de variaveis
    int quantidadeFrutas = 0;
    int contador;

    // armazenando qtd de frutas
    printf("Digite a quantidade de frutas:\n");
    scanf("%d", &quantidadeFrutas);

    // criando matriz para frutas
    char **listaFrutas = (char**) malloc(quantidadeFrutas*sizeof(char*));

    for(contador = 0; contador < quantidadeFrutas; contador++){
        listaFrutas[contador] = (char*) malloc(50*sizeof(char));
    }

    if(listaFrutas == NULL){
        exit(1);
    }

    // criando vetor para preço das frutas
    float *precoFrutas = (float*) malloc(quantidadeFrutas*sizeof(float));

    if(precoFrutas == NULL){
        exit(1);
    }

    // preenchendo matriz e vetor
    for (contador = 0; contador < quantidadeFrutas; contador++){
        printf("Digite o nome da fruta:\n");
        scanf(" %[^\n]s", listaFrutas[contador]);
        printf("Digite o preco da fruta:\n");
        scanf("%f", precoFrutas[contador]);
    }

    // pegando maior string
    int maiorString = 0;
    for (contador = 0; contador < quantidadeFrutas; contador++){
        if(strlen(listaFrutas[contador]) > quantidadeFrutas + 1){
            maiorString = strlen(listaFrutas[contador]);
        }
    }

    // realocando memoria  
    listaFrutas = (char**) realloc(listaFrutas, maiorString*sizeof(char*));
    if(listaFrutas == NULL){
        exit(1);
    }

    // listando frutas
    printf("Listagem de Frutas\n");
    for(contador = 0; contador < quantidadeFrutas; contador++){
        printf("%s %f", listaFrutas[contador], precoFrutas[contador]);
    }

    // liberando a memoria
    for(contador = 0; contador < quantidadeFrutas; contador++){
        free(listaFrutas[contador]);
    }
    free(listaFrutas);
    free(precoFrutas);

    return 0;
}
