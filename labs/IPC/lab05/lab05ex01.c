#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    FILE *arq;
    char nomeArq[100];
    printf("Digite o nome do arquivo: ");
    fgets(nomeArq, 100, stdin);

    nomeArq[strlen(nomeArq) - 1] = '\0';
    arq = fopen(nomeArq, "w");

    printf("Digite o nome de um estudante, de enter e digite o proximo nome:\n");
    printf("Para sair digite SAIR\n");

    int i = 0;
    while (i == 0)
    {
        char nomeAln[100] = "";
        fgets(nomeAln, 100, stdin);
        nomeAln[strlen(nomeAln) - 1] = '\0';

        if (strcmp(nomeAln, "SAIR") == 0)
        {
            i = 1;
            break;
        }
        fputs(nomeAln, arq);
        fputs("\n", arq);
    }
    fclose(arq);

    arq = fopen(nomeArq, "r");
    printf("\nNomes dos estudantes:\n");
    char nomesAln[100];
    while (fgets(nomesAln, 100, arq) != NULL && !feof(arq))
    {
        for (int j = 0; nomesAln[j] != '\0'; j++)
        {
            nomesAln[j] = toupper(nomesAln[j]);
        }
        printf("%s", nomesAln);
    }
    printf("\n");
    fclose(arq);
}