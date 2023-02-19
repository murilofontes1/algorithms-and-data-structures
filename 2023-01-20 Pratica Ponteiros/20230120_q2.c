#include <stdio.h>

int main(void){
    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p = %p\tValor de *p = %d", p, *p);
    return 0;
}

/*

Se tentarmos compilar o programa (não o compile ainda),
você acha que o compilador nos fornece alguma mensagem?
Se sim, responda:
    a) Esta mensagem é de erro ou advertência?
        Mensagem de erro.
    b) Por que o compilador emite tal mensagem?
        O código está
        tentando passar a variável x para
        o ponteiro p, sendo que deveria ter
        sido utilizado um & para que o ponteiro
        salvasse o endereço de x.
    c) Compile e execute o programa. A execução
    foi bem sucedida?
        Não.
    d) Modifique o trecho de código acima, de
    modo que nenhuma mensagem seja emitida
    pelo compilador.
        #include <stdio.h>

        int main(void){
            int x, *p;
            x = 100;
            p = &x;
            printf("Valor de p = %p\tValor de *p = %d", p, *p);
            return 0;
        }
    e) Compile e execute novamente o programa.
    A execução foi bem sucedida?
        Sim.
*/