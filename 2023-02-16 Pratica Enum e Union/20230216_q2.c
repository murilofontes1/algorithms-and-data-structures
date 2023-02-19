#include <stdio.h>

int main (void){
	typedef union tipo{
		char ALIMENTO[10];
		char BEBIDA[10];
		char ELETRONICO[10];
	}Tipo;
	
    typedef struct produto{
		char nome[100];
		float preco;
		Tipo tipo;		
	}Produto;
	
	Produto produto;

	printf("Digite o nome do produto.\n");
	scanf(" %[^\n]s", produto.nome);
	printf("Digite o preco do produto.\n");
	scanf("%f", &produto.preco);
	printf("Digite o tipo do produto (ALIMENTO, BEBIDA ou ELETRONICO).\n");
	scanf(" %[^\n]s", produto.tipo.ALIMENTO);
	
	printf("Produto: %s | Preco: %.1f | Tipo: %s", produto.nome, produto.preco, produto.tipo.ELETRONICO);
	
    return 0;
}
