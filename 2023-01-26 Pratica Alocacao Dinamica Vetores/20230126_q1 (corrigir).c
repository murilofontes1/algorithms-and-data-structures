#include <stdio.h>
#include <stdlib.h>

void questionario_produto(char *sexo, int *opiniao){
    char resposta1; // sexo
    int resposta2; // opiniao
    int i; // contador

    for(i = 0; i < 5; i++){
        printf("Digite o seu sexo (M/F):\n");
        scanf("%c", &resposta1);

        if(resposta1 == 'M'){
            printf("Digite sua opiniao (1 - gostei/2 - nao gostei):\n");
            scanf("%d", &resposta2);

            if(resposta2 == 1){
                sexo[i] = 'M';
                opiniao[i] = 1;
                printf("Obrigado!\n");
            } else if(resposta2 == 2){
                sexo[i] = 'M';
                opiniao[i] = 2;
                printf("Obrigado!\n");
            } else{
                printf("Resposta invalida.\n");
            }
        } else if(resposta1 == 'F'){
            printf("Digite sua opiniao (1 - gostei/2 - nao gostei):\n");
            scanf("%d", &resposta2);
            if(resposta2 == 1){
                sexo[i] = 'F';
                opiniao[i] = 1;
                printf("Obrigado!\n");
            } else if(resposta2 == 2){
                sexo[i] = 'F';
                opiniao[i] = 2;
                printf("Obrigado!\n");
            } else{
                printf("Resposta invalida.\n");
            }
        } else{
            printf("Resposta invalida.\n");
        }
    }
}

void verifica_porcentagem(char *sexo, int *opiniao){
    int aprovacoes_femininas = 0;
    int reprovacoes_masculinas = 0;
    for(int i = 0; i < 5; i++){
        if ((sexo[i] == 'F') && (opiniao[i] == 1)){ // Erro: comparison between pointer and integer
            aprovacoes_femininas++;
        }
    }

    for(int i = 0; i < 5; i++){
        if ((sexo[i] == 'M') && (opiniao[i] == 2)){ // Erro: comparison between pointer and integer
            reprovacoes_masculinas++;
        }
    }
    printf("Quantidade de pessoas do sexo feminino que aprovaram o produto: %d\n", aprovacoes_femininas);
    printf("Quantidade de pessoas do sexo masculino que desaprovaram o produto: %d\n", reprovacoes_masculinas);
}

int main(void){
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
    verifica_porcentagem(sexo, opiniao); // Erro: passing argument 2 of 'verifica_porcentagem' from incompatible pointer type
    free(sexo);
    free(opiniao);
    return 0;
}