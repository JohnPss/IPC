#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibVet(int n, int *vetor)
{
    for (int i = 1; i <= n; i++)
    {
        vetor[i - 1] = fibonacci(i);
    }
}

int busca_fibonacci(int n, int chave, int *vetor)
{
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (chave == vetor[meio])
            return meio;
        else if (chave > vetor[meio])
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main()
{
    int *vet;
    int n, nF, resultado;

    printf("deseja gerar ate qual enesimo numero? ");
    scanf("%d", &n);

    printf("Qual numero deseja checar? ");
    scanf("%d", &nF);

    vet = (int *)malloc(sizeof(int) * n);

    fibVet(n, vet);

    resultado = busca_fibonacci(n, nF, vet);

    if (resultado != -1)
    {
        printf("Indice: %d\n", resultado + 1);
    }
    else
    {
        printf("indice: %d\n ", resultado);
    }

    free(vet);

    return 0;
}
