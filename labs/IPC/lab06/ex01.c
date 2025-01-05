#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *arq = fopen("matriz.txt", "r");
    FILE *arqT = fopen("transporta.txt", "w");
    int **mtz, **mtzT;
    int ln, cl;

    fscanf(arq, "%d %d", &ln, &cl);

    mtz = (int **)malloc(ln * sizeof(int *));
    mtzT = (int **)malloc(cl * sizeof(int *));

    for (int i = 0; i < ln; i++)
    {
        mtz[i] = (int *)malloc(cl * sizeof(int));
    }

    for (int k = 0; k < ln; k++)
    {
        mtzT[k] = (int *)malloc(ln * sizeof(int));
    }

    for (int i = 0; i < ln; i++)
    {
        for (int j = 0; j < cl; j++)
        {
            fscanf(arq, "%d", &mtz[i][j]);
        }
    }
    fclose(arq);

    for (int i = 0; i < ln; i++)
    {
        for (int j = 0; j < cl; j++)
        {
            mtzT[j][i] = mtz[i][j];
        }
    }
    free(mtz);

    for (int i = 0; i < cl; i++)
    {
        for (int j = 0; j < ln; j++)
        {
            fprintf(arqT, "%d ", mtzT[i][j]);
        }
        fprintf(arqT, "\n");
    }
    free(mtzT);
    fclose(arqT);

    printf("%d %d", ln, cl);
}