#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **visitado;
int seguro(int x, int y, char **mtz, int ln, int cl)
{
    return (x >= 0 && y >= 0 && x < ln && y < cl && mtz[x][y] != 'R' && !visitado[x][y]);
}

int dfs(char **mtz, int x, int y, int ln, int cl)
{
    if (!seguro(x, y, mtz, ln, cl))
        return 0;

    if (mtz[x][y] == 'Z')
        return 1;

    visitado[x][y] = 1;
    if (dfs(mtz, x, y + 1, ln, cl))
    {
        mtz[x][y] = '*';
        return 1;
    }

    if (dfs(mtz, x, y - 1, ln, cl))
    {
        mtz[x][y] = '*';
        return 1;
    }
    if (dfs(mtz, x + 1, y, ln, cl))
    {
        mtz[x][y] = '*';
        return 1;
    }

    if (dfs(mtz, x - 1, y, ln, cl))
    {
        mtz[x][y] = '*';
        return 1;
    }

    visitado[x][y] = 0;
    return 0;
}

void printSolution(char **mtz, int ln, int cl, int x, int y)
{
    for (int i = 0; i < ln; i++)
    {
        for (int j = 0; j < cl; j++)
        {
            if (i == x && j == y)
                printf("| H ");
            else
                printf("| %c ", mtz[i][j]);
        }
        printf("\n");
    }
}

int fuga_humana(char **mtz, int ln, int cl)
{
    visitado = (int **)malloc(ln * sizeof(int *));
    for (int i = 0; i < ln; i++)
    {
        visitado[i] = (int *)malloc(cl * sizeof(int));
        memset(visitado[i], 0, cl * sizeof(int));
    }

    int xinc, yinc;

    for (int i = 0; i < ln; i++)
    {
        for (int j = 0; j < cl; j++)
        {
            if (mtz[i][j] == 'H')
            {
                xinc = i;
                yinc = j;
            }
        }
    }

    if (dfs(mtz, xinc, yinc, ln, cl))
    {
        printf("Caminho encontrado\n");
        printSolution(mtz, ln, cl, xinc, yinc);
        return 1;
    }
    else
    {
        printf("Caminho não encontrado\n");
        return 0;
    }
    for (int i = 0; i < ln; i++)
    {
        free(visitado[i]);
    }
    free(visitado);
}

int main()
{
    int nLinhas, nColunas, i, j;
    char **lbrnt;
    FILE *arq;

    if ((arq = fopen("mapa.txt", "r")) == NULL)
    {
        printf("\nErro no arq\n");
        return 1;
    }

    fscanf(arq, "%d", &nLinhas);
    fscanf(arq, "%d", &nColunas);

    lbrnt = (char **)malloc(sizeof(char *) * nLinhas);
    for (i = 0; i < nLinhas; i++)
        lbrnt[i] = (char *)malloc(sizeof(char) * nColunas);

    fgetc(arq);
    for (i = 0; i < nLinhas; i++)
    {
        for (j = 0; j < nColunas; j++)
        {
            lbrnt[i][j] = fgetc(arq);
        }
        fgetc(arq);
    }

    fuga_humana(lbrnt, nLinhas, nColunas);

    for (i = 0; i < nLinhas; i++)
        free(lbrnt[i]);
    free(lbrnt);

    fclose(arq);

    return 0;
}