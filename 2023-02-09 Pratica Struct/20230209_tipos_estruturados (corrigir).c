#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 30
#define MAX_TURMAS 3

typedef struct aluno{
    int mat;
    char nome[81];
    float notas[3];
    float media;
}Aluno;

typedef struct turma {
    char id;
    int vagas;
    Aluno* alunos[MAX_ALUNOS];
}Turma;

Turma* turmas[MAX_TURMAS];

int validar_turma(Turma** turma){
    if (turma[0] == NULL){
        printf("Nao ha turmas cadastradas.\n");
        return 1;
    }
}

Turma* cria_turma(char id){
    int i;
    Turma* turma1 = (Turma*) malloc(sizeof(Turma));
    if(turma1 == NULL){
        exit (1);
    }
    turma1->id = id;
    turma1->vagas = MAX_ALUNOS;
    for(i = 0; i < MAX_ALUNOS; i++){
        turma1->alunos[i] = NULL;
    }
    printf("Turma %c criada com sucesso!\n\n", id);
    return turma1;
}

Turma** imprime_turmas(Turma** turmas, int n){
    int i;
    for(i = 0; i < MAX_TURMAS; i++){
        printf("Turma %c - %d vagas disnponiveis\n", turmas[n]->id, turmas[n]->vagas);
    }
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    int i, j;
    turma->vagas -= 1;
    for(i = 0; i < MAX_ALUNOS; i++){
        if(turma->alunos[i] == NULL){
            turma->alunos[i] == (Aluno*) malloc(sizeof(Aluno));
            for(j = 0; j < 3; j++){
                turma->alunos[i]->notas[j] = 0;
            }
        turma->alunos[i]->mat = mat;
        strcpy(turma->alunos[i]->nome, nome);
        printf("Aluno matriculado com sucesso.\n");
        break;
        }
    }
}

int main(void){
    int op, i, index = 0, controle, mat;
    char id, nome[81];
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas! Este programa gerencia as turmas ofertadas, fornecendo as uncionalidades de matricula, lancamento de notas e listagem de alunos.\nAutor: Murilo Fontes\tVersao: 1.0\n");
    do{
        printf("MENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Buscar turma\n7 - Sair\n\nDigite sua opcao:");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Criando nova turma...\n");
                if(index >= MAX_TURMAS){
                    printf("Numero maximo de turmas atingido.\n");
                    break;
                }
                printf("Digite o id da turma:");
                scanf(" %[^\n]s", &id);
                turmas[index] = cria_turma(id);
                index++;
            break;

            case 2:
                controle = validar_turma(turmas);
                if(controle == 1){break;}
                printf("Listando turmas...\n");
                imprime_turmas(id, turma[id]->vagas);
                // falta fazer
            break;

            case 3:
                controle = validar_turma(turmas);
                if(controle == 1){break;}
                printf("Digite o id da turma.");
                scanf(" %[^\n]s", &id);
                printf("Digite a matricula do aluno.");
                scanf("%d", &mat);
                printf("Digite o nome do aluno.");
                scanf(" %[^\n]s", nome);
                for(i = 0; i < MAX_TURMAS; i++){
                    if(turmas[i]->vagas == 0){
                        printf("Nao ha vagas na turma.\n");
                        break;
                    } else if(turmas[i]->id == id){
                        matricula_aluno(turmas[i], mat, nome);
                        break;
                    } else{
                        printf("Turma inexistente.\n");
                        break;
                    }
                }
            break;

            case 4:
                controle = validar_turma(turmas);
                if(controle == 1){break;}
            break;

            case 5:
                controle = validar_turma(turmas);
                if(controle == 1){break;}
            break;

            case 6:
                controle = validar_turma(turmas);
                if(controle == 1){break;}
            break;

            case 7:
            break;

            default:
                printf("Opcao invalida.");
            break;
        }
    }while(op != 7);

    printf("Obrigado por usar este programa!");
    return 0;
}