#include <stdio.h>
#include <stdlib.h>

void questionario_produto(char *sexo, int *opiniao){
    int i; // contador
    for(i = 0; i < 5; i++){
        printf("Digite o seu sexo (M/F):\n");
        scanf(" %[^\n]s", &sexo[i]);
        printf("Digite sua opiniao (1 - gostei/2 - nao gostei):\n");
        scanf("%d", &opiniao[i]);
    }
}

int main(void){
    int i;
    float percentMacho, percentFemea, qtdHomens = 0, qtdMulheres = 0;
    char *sexo = (char*) malloc (5*sizeof(char));
    if(sexo == NULL){
        printf("Memória insuficiente.");
        return 1;
    }
    int *opiniao = (int*) malloc (5*sizeof(int));
    if(opiniao == NULL){
        printf("Memória insuficiente.");
        return 1;
    }
    questionario_produto(sexo, opiniao); // Erro: passing argument 2 of 'questionario_produto' from incompatible pointer type
    
    for(i = 0; i < 5; i++){
        if(sexo[i] == 'M'){
            qtdHomens++;
        } else if(sexo[i]  == 'F'){
            qtdMulheres++;
        }
    }
    float aprovacoes_femininas = 0;
    float reprovacoes_masculinas = 0;
    for(int i = 0; i < 5; i++){
        if ((sexo[i] == 'F') && (opiniao[i] == 1)){ // Erro: comparison between pointer and integer
            aprovacoes_femininas++;
        } 
         if ((sexo[i] == 'M') && (opiniao[i] == 2)){ // Erro: comparison between pointer and integer
            reprovacoes_masculinas++;
        }
    } 

    percentFemea = (aprovacoes_femininas/qtdMulheres)*100;
    percentMacho = (reprovacoes_masculinas/qtdHomens)*100;
    printf("Porcentagem de pessoas do sexo feminino que aprovaram o produto: %.1f%%\n", percentFemea);
    printf("Quantidade de pessoas do sexo masculino que desaprovaram o produto: %.1f%%\n", percentMacho);
    /* verifica_porcentagem(sexo, opiniao, qtdHomens, qtdMulheres); */ // Erro: passing argument 2 of 'verifica_porcentagem' from incompatible pointer type
    free(sexo);
    free(opiniao);
    return 0;
}