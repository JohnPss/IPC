#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *arq;
    char nomeArq[100];
    char mtz[20][100];

    printf("Digite o nome do arquivo: ");
    fgets(nomeArq, 100, stdin);
    nomeArq[strcspn(nomeArq, "\n")] = 0;

    arq = fopen(nomeArq, "w");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita");
        return 1;
    }
    printf("Digite uma string (max de 20 strings), digite FIM para encerrar a entrada:\n");
    char str[100];
    int i = 0;
    while (i < 20)
    {
        fgets(str, 100, stdin);
        if (strcmp(str, "FIM\n") == 0)
        {
            break;
        }
        fputs(str, arq);
        i++;
    }
    fclose(arq);
    arq = fopen(nomeArq, "r");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }
    i = 0;
    char str1[100];
    while (fgets(str1, 100, arq) != NULL && i < 20)
    {
        str1[strcspn(str1, "\n")] = 0;
        strcpy(mtz[i], str1);
        i++;
    }
    fclose(arq);

    printf("Digite uma palavra que deseja achar na matriz: ");
    char str2[100];
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;

    for (int j = 0; j < i; j++)
    {
        if (strstr(mtz[j], str2) != NULL)
        {
            printf("A frase \"%s\" existe na linha %d, sendo ela \"%s\"\n", str2, j, mtz[j]);
        }
    }

    return 0;
}