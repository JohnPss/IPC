#include <stdio.h>
#include <string.h>

void ctdFrq(char *s)
{
    int tblascii[128] = {0};

    for (int i = 0; s[i] != '\0'; i++)
        tblascii[s[i]]++;

    for (int i = 0; i < 128; i++)
    {
        if (tblascii[i] > 0)
            printf("%d, %d\n", i, tblascii[i]);
    }
}

void tcldRplc(char *s)
{
    char str1[128] = "";
    char *plvrTpm = strtok(s, " ");

    while (plvrTpm != NULL)
    {
        if (strcmp(plvrTpm, "teclado") != 0)
        {
            strcat(str1, plvrTpm);
            strcat(str1, " ");
        }
        else
        {
            strcat(str1, "teclado e mouse");
            strcat(str1, " ");
        }
        plvrTpm = strtok(NULL, " ");
    }

    if (str1[0] != '\0')
        str1[strlen(str1) - 1] = '\0';

    printf("%s", str1);
}

void eclalnRplc(char *str)
{
    char str2[128] = "";
    char *plvrstr = strtok(str, " ");

    while (plvrstr != NULL)
    {
        if (strcmp(plvrstr, "aluno") != 0 && strcmp(plvrstr, "escola") != 0)
        {
            strcat(str2, plvrstr);
            strcat(str2, " ");
        }
        else if (strcmp(plvrstr, "aluno") == 0)
        {
            strcat(str2, "estudante");
            strcat(str2, " ");
        }
        else if (strcmp(plvrstr, "escola") == 0)
        {
            strcat(str2, "universidade");
            strcat(str2, " ");
        }

        plvrstr = strtok(NULL, " ");
    }

    if (str2[0] != '\0')
        str2[strlen(str2) - 1] = '\0';

    printf("%s", str2);
}

void mtzMtpl(int cl[], int ln[])
{
}

int main()
{

    int choice;
    printf("Escolha uma opção:\n");
    printf("1. ctdFrq\n");
    printf("2. tcldRplc\n");
    printf("3. eclalnRplc\n");
    scanf("%d", &choice);

    char input[128];
    printf("Digite uma sequencia de caracteres: ");
    fgets(input, sizeof(input), stdin);

    switch (choice)
    {
    case 1:
        ctdFrq(input);
        break;
    case 2:
        tcldRplc(input);
        break;
    case 3:
        eclalnRplc(input);
        break;
    default:
        printf("Opção inválida.\n");
        break;
    }

    // ctdFrq(s);
}