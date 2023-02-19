#include <stdio.h>

int main(void){
    int a, b, c, d; // criando as variáveis inteiras
    int *p1; // criando ponteiro p1
    int *p2 = &a; // criando ponteiro p2 e atribuindo a ele o endereço de a
    int *p3 = &c; // criando ponteiro p3 e atribuindo a ele o endereço de c
    p1 = p2; // atribuindo p2 à p1
    *p2 = 10; // alterando o valor de a para 10;
    b = 20; // atribuindo o valor 20 a b;
    int **pp; // criando o ponteiro para ponteiro **pp
    pp = &p1; // atribuindo o endereço de p1 a pp
    *p3 = **pp; // atribuindo o conteúdo de pp (p1 = p2 = 10) a p3;
    int *p4 = &d; // criando ponteiro p4 e atribuindo o endereço de d
    *p4 = b + (*p1)++; // atribuindo o valor 30 (20 + 10) à p4, depois incrementando 1 em p1 = p2 = pp = 11
    printf("%d\t%d\t%d\t%d\n", a, b, c, d); // imprime 11, 20, 10, 30
    return 0;
}