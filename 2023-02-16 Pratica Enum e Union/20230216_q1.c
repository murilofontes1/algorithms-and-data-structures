#include <stdio.h>
#include <string.h>

int main (void){
    typedef enum genero{
        MASCULINO = 0,
        FEMININO
    }Genero;

    typedef struct pessoa{
        char nome[50];
        int idade;
        Genero genero;
    }Pessoa;

	const char* generos[] = {"Masculino", "Feminino"};
	
    Pessoa pessoa;
    int genero = 0;

    printf("Digite seu nome: \n");
    scanf(" %[^\n]s", &pessoa.nome);
    printf("Digite sua idade:\n");
    scanf("%d", &pessoa.idade);
    printf("Digite seu genero (0 para MASCULINO ou 1 para FEMININO)\n");
    scanf("%d", (int*)&pessoa.genero);

    if(pessoa.genero == MASCULINO){
        printf("Nome: %s | Idade: %d | Genero: %s", pessoa.nome, pessoa.idade, generos[MASCULINO]);
        
    } else{
        printf("Nome: %s | Idade: %d | Genero: %s", pessoa.nome, pessoa.idade, generos[FEMININO]);
    }

    return 0;
}
