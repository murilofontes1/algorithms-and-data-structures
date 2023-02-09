#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{
    char nome[50];
    int salario;
    char cargo[20];
}Funcionario;

int main(void){
    int qtdFuncionarios, i;
    printf("Digite a quantidade de funcionarios que deseja cadastrar. \n");
    scanf("%d", &qtdFuncionarios);

    Funcionario * funcionario = (Funcionario*) malloc(qtdFuncionarios*sizeof(Funcionario));
    if (funcionario == NULL){
        printf("Memória insuficiente.");
        exit(1);
    }

    for(i = 0; i < qtdFuncionarios; i++){
        printf("Digite o nome do funcionario %d. \n", i + 1);
        scanf(" %[^\n]s", funcionario[i]->nome);
        printf("Digite o salario do funcionario %d. \n", i + 1);
        scanf("%f", &funcionario[i]->salario);
        printf("Digite o cargo do funcionario %d. \n", i + 1);
        scanf(" %[^\n]s", funcionario[i]->cargo);
    }

    for(i = 0; i < qtdFuncionarios; i++){
        printf("Funcionario %d: \n", i + 1);
        printf("Nome: %s | Salario: %f | Cargo: %s \n", funcionario->nome, funcionario->salario, funcionario->cargo);
    }

    free(funcionario);
    return 0;
}