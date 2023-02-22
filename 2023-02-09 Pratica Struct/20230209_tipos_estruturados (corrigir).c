#include <stdio.h>
#include <string.h>

struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma {
    char id;
    int vagas;
    Aluno* alunos[30];
};
typedef struct turma Turma;

Turma* turmas[3];

Turma* cria_turma(char id){
    Turma* turma1 = (Turma*) malloc(sizeof(Turma));
    turma1->id = id;
    turma1->vagas = 30;
    int i;
    for(i = 0; i < 30; i++){
        turma1->alunos[i] = NULL;
    }
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    int i;
    for(i = 0; i < 30; i++){
        if(turma->alunos[i] == NULL){
            turma->id = turma;
            turma->alunos[i]->mat = mat;
            strcpy(turma->alunos[i]->nome, nome);
            int j;
            for(j = 0; j < 3; j++){
                turma->alunos[i]->notas[j] = 0;
            }
        }
    }
}

void lanca_notas(Turma* turma){
    int turma, i, j;
    float media = 0;
    for(turma = 0; turma < 3; turma++){
        if(turma == turmas[i]->id){
            for(i = 0; i < 30; i++){
                if(turma->alunos[i] != NULL){
                    for(j = 0; j < 3; j++){
                        printf("Digite a nota %d do aluno %d.", j+1, i+1);
                        scanf("%f", &turma->alunos[i]->notas[j]);
                        media += turma->alunos[i]->notas[j];
                    }
                    turma->alunos[i]->media = media;
                } else{
                    printf("Turma cheia!");
                }
            }
        } else{
            printf("Turma inexistente!");
        }
    }   
}

void imprime_alunos(Turma* turma){
    int i, j;
    for(i = 0; i < 30; i++){
        if(turma->alunos[i] != NULL){
            printf("Matrícula: %i\nNome: %s\nMedia: %.1f\n");
        }
    }
}

int main(void){
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\nAutor: Murilo Fontes\tVersao: 1.0");
    int opcao = 0;
    do{
        printf("MENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair");
        printf("Digite sua opcao:");
        scanf("%i", &opcao);

        if(opcao == 1){
            printf("Criando nova turma...\nDigite um id:");
            char id;
            scanf("%c", &id);
            cria_turma(id);
            printf("Turma %c criada com sucesso!", id);
        }

        if(opcao == 2){
            printf("Listando turmas...");
            // falta fazer
        }

        if (opcao == 3){
            char id;
            int mat;
            char nome[81];
            printf("Matriculando aluno...\nDigite o id da turma:");
            scanf("%c", &id);
            printf("Digite a matrícula:");
            scanf("%d", &mat);
            printf("Digite o nome:");
            scanf(" %[^\n]s", nome);
            matricula_aluno(id, mat, nome);
        }

        if (opcao == 4){
            char id;
            printf("Lançando notas...\nDigite o id da turma:");
            scanf("%c", &id);
            lanca_notas(id);
        }

        if (opcao == 5){
            char id;
            printf("Listando alunos...\nDigite o id da turma:");
            scanf("%c", &id);
            imprime_alunos(id);
        }

    }while(opcao != 6);
    printf("Obrigado por usar este programa!");
    return 0;
}
