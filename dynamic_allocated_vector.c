#include <stdio.h>
#include <stdlib.h>

void questionario_produto(char *sexo, int *opiniao){
    char resposta1;
    int resposta2;

    for(int i = 0; i < 5; i++){
        printf("Digite o seu sexo (M/F):\n");
        scanf("%[^\n]", &resposta1);
        switch(resposta1){
            case 'M':
                printf("Digite sua opinião sobre o produto (1 para gostei, 2 para não gostei):\n");
                scanf("%[^\n]", &resposta2);
                switch(resposta2){
                    case 1:
                        sexo[i] = "M"; // Erro: assignment makes integer from pointer without a cast
                        opiniao[i] = 1;
                        printf("Obrigado por participar da pesquisa\n");
                    break;

                    case 2:
                        sexo[i] = "M";
                        opiniao[i] = 2; // Erro: assignment makes integer from pointer without a cast
                        printf("Obrigado por participar da pesquisa\n");
                    break;
                }
            break;

            case 'F':
                printf("Digite sua opinião sobre o produto (1 para gostei, 2 para não gostei):\n");
                scanf("%[^\n]", resposta2);
                switch(resposta2){
                    case 1:
                        sexo[i] = "F"; // Erro: assignment makes integer from pointer without a cast
                        opiniao[i] = 1;
                        printf("Obrigado por participar da pesquisa\n");
                    break;

                    case 2:
                        sexo[i] = "F"; // Erro: assignment makes integer from pointer without a cast
                        opiniao[i] = 2;
                        printf("Obrigado por participar da pesquisa\n");
                    break;
                }
            break;
        }
    }
}

void verifica_porcentagem(char *sexo, int *opiniao){
    int aprovacoes_femininas, reprovacoes_masculinas;
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
