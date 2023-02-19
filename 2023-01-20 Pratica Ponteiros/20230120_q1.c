#include <stdio.h>

int main(void){
    int x, y, *p; // criando as variáveis inteiras x, y e o ponteiro para inteiro *p´;
    y = 0; // atribuindo o valor 0 à y;
    p = &y; // atribuindo o endereço da variável y ao ponteiro p;
    x = *p; // atribuindo o conteúdo do ponteiro p à variável x;
    x = 4; // atribuindo o valor 4 à variável x;
    (*p)++; // somando 1 unidade ao conteúdo do ponteiro p, que aponta para y;
    --x; // decrementando 1 unidade do conteúdo de x;
    (*p) += x; // armazenando no ponteiro p (que aponta para y) o valor dele mesmo mais o valor de x;

    printf("x: %d, y: %d, *p: %d", x, y, *p); // exibe x = 3, y = 4, *p = 4
    return 0;
}