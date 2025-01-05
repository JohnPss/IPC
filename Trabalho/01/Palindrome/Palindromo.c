#include <stdio.h>
#include <ctype.h>
#include <string.h>

int verificar_palindromo(char *str)
{
    char strinvetida[1000];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalnum(str[i]))
        {
            strinvetida[j++] = tolower(str[i]);
        }
    }
    strinvetida[j] = '\0';

    int inc = 0;
    int fim = j - 1;

    while (inc < fim)
    {
        if (strinvetida[inc++] != strinvetida[fim--])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char str[1000];
    printf("Digite uma string sem acentos ");
    fgets(str, sizeof(str), stdin);

    if (verificar_palindromo(str))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}
