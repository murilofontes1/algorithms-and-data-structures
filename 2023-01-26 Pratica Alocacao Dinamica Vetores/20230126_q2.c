#include <stdio.h>

int main(void){
    printf("Digite o numero de questoes da prova:");
    int numeroQuestoes;
    scanf("%d", &numeroQuestoes);
    char* gabarito = (char*) malloc(numeroQuestoes*sizeof(char));
    char* respostasAlunos = (char*) malloc(10*numeroQuestoes*sizeof(char));
    float* notas = (float*) malloc(10*sizeof(float));
    printf("Digite o gabarito da prova:\n");
    int i, alunos;
    for(i = 0; i < numeroQuestoes; i++){
        printf("Resposta da questao %d:", i+1);
        scanf(" %[^\n]", &gabarito[i]);
    }
    for(alunos = 0; alunos < 10; alunos++){
        for(i = 0; i < numeroQuestoes; i++){
            printf("Digite a resposta do aluno %d para a questao %d:", alunos+1, i+1);
            scanf(" %[^\n]", &respostasAlunos[i]);
            if(respostasAlunos[i] == gabarito[i]){
                notas[alunos] = 10/numeroQuestoes;
            }
        }
    }

    float aprovados = 0;
    for(alunos = 0; alunos < 10; alunos++){
        printf("Nota do aluno %d: %.1f\n", alunos+1, notas[alunos]);
        if(notas[alunos] >= 6){
            aprovados++;
        }
    }  
    
    printf("Porcentagem de aprovacao: %.0f%%\n", ((aprovados/10)*100));
    return 0;
}