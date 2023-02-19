#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
    *area = (3*(pow(l, 2))*sqrt(3))/2;
    *perimetro = 6*l;
    printf("Area do hexagono: %.1f | Perimetro do hexagono: %.1f", *area, *perimetro);
}

int main(void){
    float area, perimetro;
    float *a = &area;
    float *p = &perimetro;
    int qtdLados = 0;
    printf("Digite a quantidade de lados do hexagono.\n");
    scanf("%d", &qtdLados);
    calcula_hexagono(qtdLados, a, p);
    return 0;
}