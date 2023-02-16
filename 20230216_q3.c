#include <stdio.h>

int main (void){
	typedef enum mes{
		JANEIRO = 1,
		FEVEREIRO,
		MARCO,
		ABRIL,
		MAIO,
		JUNHO,
		JULHO,
		AGOSTO,
		SETEMBRO,
		OUTUBRO,
		NOVEMBRO,
		DEZEMBRO,
		MAX_MESES
	}Mes;
	
	typedef struct data{
		int dia;
		Mes mes;
		int ano;
	}Data;
	
	Data data;
	int i;
	
	printf("Digite o dia:\n");
	scanf("%d", &data.dia);
	printf("Digite o mes (1 para Janeiro, ..., 12 para Dezembro):\n");
	scanf("%d", &data.mes);
	printf("Digite o ano:\n");
	scanf("%d", &data.ano);
	
	for(i = 1; i < MAX_MESES; i++){
		if(i == data.mes && data.mes <= 9){
			printf("%d/ 0 %d/%d", data.dia, data.mes, data.ano);
			break;
		} else{
			printf("%d/%d/%d", data.dia, data.mes, data.ano);
			break;
		}
	}
	
    return 0;
}
