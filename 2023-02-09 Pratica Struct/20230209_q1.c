#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    char nome[50];
    float salario;
    int id;
    char cargo[20];
}Funcionario;

void cadastra_funcionarios(Funcionario * funcionario, int qtdFuncionarios){
	int i;
	for(i = 0; i < qtdFuncionarios; i++){
        printf("Digite o nome do funcionario %d. \n", i + 1);
        scanf(" %[^\n]s", funcionario[i].nome);
        printf("Digite o salario do funcionario %d. \n", i + 1);
        scanf("%f", &funcionario[i].salario);
        printf("Digite o identificador do funcionario %d. \n", i + 1);
        scanf("%d", &funcionario[i].id);
        printf("Digite o cargo do funcionario %d. \n", i + 1);
        scanf(" %[^\n]s", funcionario[i].cargo);
    }
}

void imprime_funcionarios(Funcionario * funcionario, int qtdFuncionarios){
	int i;
	for(i = 0; i < qtdFuncionarios; i++){
        printf("Funcionario %d: \n", i + 1);
        printf("Nome: %s | Salario: %.1f | Identificador: %d | Cargo: %s \n", funcionario[i].nome, funcionario[i].salario, funcionario[i].id, funcionario[i].cargo);
    }
}

void altera_salario(Funcionario * funcionario, int qtdFuncionarios){
	int id, i;
	printf("Digite o identificador do funcionario a ter seu salario alterado. \n");
	scanf("%d", &id);
	for(i = 0; i < qtdFuncionarios; i++){
		if(funcionario[i].id == id){
			printf("Digite o novo salario do funcionario %d. \n", i + 1);
			scanf("%f", &funcionario[i].salario);
		}
	}
}

void imprime_maior_menor_salario(Funcionario * funcionario, int qtdFuncionarios){
	int i;
	float maiorSalario = 0;
	float menorSalario = 9999;
	char cargoMaiorSalario[20];
	char cargoMenorSalario[20];
	for (i = 0; i < qtdFuncionarios; i++){
		if(funcionario[i].salario > maiorSalario){
			maiorSalario = funcionario[i].salario;
			strcpy(cargoMaiorSalario, funcionario[i].cargo);
		}
		if(funcionario[i].salario < menorSalario){
			menorSalario = funcionario[i].salario;
			strcpy(cargoMenorSalario, funcionario[i].cargo);
		}
	}
	printf("Cargo com maior salario : %s (%.1f reais)\n", cargoMaiorSalario, maiorSalario);
	printf("Cargo com menor salario : %s (%.1f reais)\n", cargoMenorSalario, menorSalario);
}

int main(void){
    int qtdFuncionarios, i;
    printf("Digite a quantidade de funcionarios que deseja cadastrar. \n");
    scanf("%d", &qtdFuncionarios);

    Funcionario * funcionario = (Funcionario*) malloc(qtdFuncionarios*sizeof(Funcionario));
    if (funcionario == NULL){
        printf("Memória insuficiente.");
        exit(1);
    }

	cadastra_funcionarios(funcionario, qtdFuncionarios);
    imprime_funcionarios(funcionario, qtdFuncionarios);
    imprime_maior_menor_salario(funcionario, qtdFuncionarios);
    

    free(funcionario);
    return 0;
}
