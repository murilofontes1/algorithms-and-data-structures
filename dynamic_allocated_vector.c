#include <stdio.h>
#include <stdlib.h>

void questionario_produto(int *sexo, int *opiniao){
    int resposta1;
    int resposta2;

    for(int i = 0; i < 5; i++){
        printf("Digite o seu sexo (1 para M, 2 para F):\n");
        scanf("%d", &resposta1);
        switch(resposta1){
            case 1:
                printf("Digite sua opinião sobre o produto (1 para gostei, 2 para não gostei):\n");
                scanf("%d", &resposta2);
                switch(resposta2){
                    case 1:
                        sexo[i] = 1; // Erro: assignment makes integer from pointer without a cast
                        opiniao[i] = 1;
                        printf("Obrigado por participar da pesquisa\n");
                    break;

                    case 2:
                        sexo[i] = 1;
                        opiniao[i] = 2; // Erro: assignment makes integer from pointer without a cast
                        printf("Obrigado por participar da pesquisa\n");
                    break;
                }
            break;

            case 2:
                printf("Digite sua opinião sobre o produto (1 para gostei, 2 para não gostei):\n");
                scanf("%d", resposta2);
                switch(resposta2){
                    case 1:
                        sexo[i] = 2; // Erro: assignment makes integer from pointer without a cast
                        opiniao[i] = 1;
                        printf("Obrigado por participar da pesquisa\n");
                    break;

                    case 2:
                        sexo[i] = 2; // Erro: assignment makes integer from pointer without a cast
                        opiniao[i] = 2;
                        printf("Obrigado por participar da pesquisa\n");
                    break;
                }
            break;
        }
    }
}

void verifica_porcentagem(int *sexo, int *opiniao){
    int aprovacoes_femininas = 0;
    int reprovacoes_masculinas = 0;
    for(int i = 0; i < 5; i++){
        if ((sexo[i] == 2) && (opiniao[i] == 1)){ // Erro: comparison between pointer and integer
            aprovacoes_femininas++;
        }
    }

    for(int i = 0; i < 5; i++){
        if ((sexo[i] == 1) && (opiniao[i] == 2)){ // Erro: comparison between pointer and integer
            reprovacoes_masculinas++;
        }
    }
    printf("Quantidade de pessoas do sexo feminino que aprovaram o produto: %d\n", aprovacoes_femininas);
    printf("Quantidade de pessoas do sexo masculino que desaprovaram o produto: %d\n", reprovacoes_masculinas);
}

int main(void){
    int *sexo = (int*) malloc (5*sizeof(int));
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
