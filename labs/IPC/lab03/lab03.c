#include <stdio.h>
#include <math.h>

double cuboCalc(int x, int y)
{
    double soma = 0.0;
    for (int i = x; i <= y; i++)
    {
        if (i % 2 == 0)
        {
            soma += pow(i, 3);
        }
    }
    return soma;
}

int cuboAB()
{
    int a = 0, b = 0;

    do
    {
        printf("\nDigite o numero A:");
        scanf("%d", &a);
        printf("\nDigite o numero B:");
        scanf("%d", &b);

        if (b == 0 && a == 0)
            break;

        if (a > b)
        {
            printf("A soma dos cubos dos numeros entre A e B é: %.2lf\n", cuboCalc(b, a));
        }
        else if (b > a)
        {
            printf("A soma dos cubos dos numeros entre B e A é: %.2lf\n", cuboCalc(a, b));
        }
        else
        {
            printf("Não existe nenhum numero valido entre A e B!\n");
        }
    } while (1);
}

int main()
{
    cuboAB();
}
