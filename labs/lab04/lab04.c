#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ctdFrq(char *s)
{
    int tblascii[128] = {0};

    for (int i = 0; s[i] != '\0'; i++)
        tblascii[s[i]]++;

    for (int i = 0; i < 128; i++)
    {
        if (tblascii[i] > 0)
            printf("%c, %d\n", i, tblascii[i]);
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

void clcMtrz(int **A, int **B, int **C, int clA, int lnA, int clB, int lnB)
{
    for (int i = 0; i < clA; i++)
    {
        for (int j = 0; j < lnB; j++)
        {
            C[i][j] = 0;
            for (int z = 0; z < clA; z++)
            {
                C[i][j] += A[i][z] * B[z][j];
            }
        }
    }

    printf("Reultado:\n");
    for (int i = 0; i < clA; i++)
    {
        for (int j = 0; j < lnB; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int choice;

    while (1)
    {

        printf("Escolha uma opção:\n");
        printf("1) Checar a frquencia de cada caracter.\n");
        printf("2) Achar e substituir a palavra teclado.\n");
        printf("3) Achar e substituir as palavras teclado e estudante.\n");
        printf("4) Multiplicar duas matrizes.\n");
        printf("5) Sair.\n");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            char strex1[128];
            printf("Digite uma string: ");
            fgets(strex1, 128, stdin);
            ctdFrq(strex1);
            break;
        case 2:
            char strex2[128];
            printf("Digite uma string: ");
            fgets(strex2, 128, stdin);
            tcldRplc(strex2);
            break;
        case 3:
            char strex3[128];
            printf("Digite uma string: ");
            fgets(strex3, 128, stdin);
            eclalnRplc(strex3);
            break;

        case 4:
            int **A, **B, **C;
            int clA, lnA, clB, lnB;

            printf("Digite o numero de colunas e linhas da matriz A: ");
            scanf("%d %d", &clA, &lnA);
            printf("Digite o numero de colunas e linhas da matriz B: ");
            scanf("%d %d", &clB, &lnB);

            if (clA != lnB)
            {
                printf("Impossivel multiplicar as matrizes\n");
                return 1;
            }

            A = (int **)malloc(clA * sizeof(int *));
            B = (int **)malloc(clB * sizeof(int *));
            C = (int **)malloc(clA * sizeof(int *));

            for (int i = 0; i < clA; i++)
            {
                A[i] = (int *)malloc(lnA * sizeof(int));
            }
            for (int i = 0; i < clB; i++)
            {
                B[i] = (int *)malloc(lnB * sizeof(int));
                C[i] = (int *)malloc(lnB * sizeof(int));
            }

            printf("Digite os elementos da matriz A:\n");
            for (int i = 0; i < clA; i++)
            {
                for (int j = 0; j < lnA; j++)
                {
                    scanf("%d", &A[i][j]);
                }
            }

            printf("Digite os elementos da matriz B:\n");
            for (int i = 0; i < clB; i++)
            {
                for (int j = 0; j < lnB; j++)
                {
                    scanf("%d", &B[i][j]);
                }
            }

            clcMtrz(A, B, C, clA, lnA, clB, lnB);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    }
}