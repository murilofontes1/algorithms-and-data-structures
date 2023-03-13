#include <stdio.h>
#include <ctype.h> /* funçao toupper */

int main(void){
    int c;
    char entrada[121]; // armazena nome do arquivo de entrada
    char saida[121]; // armazena nome do arquivo de saida
    FILE *e; // ponteiro do arquivo de entrada
    FILE *s; // ponteiro de arquivo de saida

    /* pede ao usuário os nomes dos arquivod */
    printf("Digite o nome do arquivo de entrada (com extensao): ");
    scanf("%120s", entrada);
    printf("Digite o nome do arquivo de saida (com extensao): ");
    scanf("%120s", saida);

    /* abre arquivos para leitura e para escrita */
    e = fopen(entrada, "rt");
    if(e == NULL){
        printf("Nao foi possivel abrir o arquivo de entrada.\n");
        return 1;
    }
    s = fopen(saida, "wt");
    if(s == NULL){
        printf("Nao foi possivel abrir o arquivo de saida.\n");
        fclose(e);
        return 1;
    }

    /* le da entrada e escreve na saida */
    while((c = fgetc(e)) != EOF){
        fputc(toupper(c), s);
    }
    /* fecha arquivos */
    fclose(e);
    fclose(s);
    return 0;
}