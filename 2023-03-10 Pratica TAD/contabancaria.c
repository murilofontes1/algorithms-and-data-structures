#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

struct contabancaria{
    char titular[81];
    int numero;
    float saldo;
};

ContaBancaria * cria_conta(char titular[81], int numero, float saldo){
    ContaBancaria * c = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    if(c == NULL){
        exit(1);
    }
    strcpy(c->titular, titular);
    c->numero = numero;
    c->saldo = saldo;
    return c;
}

void deposita(ContaBancaria*c, float valor){
    c->saldo += valor;
}

void saca(ContaBancaria*c, float valor){
    c->saldo -= valor;
}

void transfere(ContaBancaria*c1, ContaBancaria*c2, float valor){
    c1->saldo -= valor;
    c2->saldo += valor;
}

float saldo(ContaBancaria*c){
    float a = c->saldo;
    return a;
}

void exclui_conta(ContaBancaria*c){
    free(c);
}