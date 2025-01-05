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

void tcldrplc(char *strtcld, char *strmdf)
{
    int i = 0, j = 0;
    int tmn = strlen(strtcld);
    while (i < tmn)
    {
        if (strncmp(&strtcld[i], "teclado", 7) == 0)
        {
            strcpy(&strmdf[j], "teclado ou mouse");
            i += 7;
            j += 16;
        }
        else
        {
            strmdf[j++] = strtcld[i++];
        }
    }
    strmdf[j] = '\0'; // Termina
}

void alnEsclRplc(char *srcEx03, char *strMdfEx03)
{
    int x = 0, z = 0;
    int length = strlen(srcEx03);
    while (x < length)
    {
        if (strncmp(&srcEx03[x], "aluno", 5) == 0)
        {
            strcpy(&strMdfEx03[z], "estudante");
            x += 5;
            z += 9;
        }
        else if (strncmp(&srcEx03[x], "escola", 6) == 0)
        {
            strcpy(&strMdfEx03[z], "universidade");
            x += 6;
            z += 12;
        }
        else
        {
            strMdfEx03[z++] = srcEx03[x++];
        }
    }
    strMdfEx03[z] = '\0';
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

        printf("\nEscolha uma opção:\n");
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
            char strtcld[1000];
            char strmdf[2000];

            printf("digite uma frase: ");
            fgets(strtcld, 1000, stdin);
            strtcld[strcspn(strtcld, "\n")] = 0;

            tcldrplc(strtcld, strmdf);

            printf("%s\n", strmdf);
            break;
        case 3:
            char strEx3[1000];
            char strMdfEx3[2000];

            printf("Digite uma frase: ");
            fgets(strEx3, 1000, stdin);
            strEx3[strcspn(strEx3, "\n")] = 0;
            alnEsclRplc(strEx3, strMdfEx3);

            printf("%s\n", strMdfEx3);
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