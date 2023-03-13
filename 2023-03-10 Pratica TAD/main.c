#include <stdio.h>
#include "contabancaria.h"

ContaBancaria * contas[10];

int main(void){
    char nome[81];
    int numeroConta, index = 0, i;
    float saldo;
    printf("1 - Cria conta\n2 - Deposita\n3 - Saca\n4 - Transfere\n5 - Saldo\n6 - Excluir conta\n");
    int op;
    scanf("%d", &op);
    switch(op){
        case 1:
            printf("Digite o titular da conta\n");
            scanf(" %[^\n]s", nome);
            printf("Digite o numero da conta\n");
            scanf("%d", &numeroConta);
            printf("Digite o saldo inicial da conta\n");
            scanf("%f", &saldo);
            if(index < 10){
                contas[index] = cria_conta(nome, numeroConta, saldo);
                float teste = saldo(&contas[0]);
                index++;
            }
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

        case 5:
        break;

        case 6:
        break;
    }
    return 0;
}