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
    char str2[128] = "";
    char *plvrTpm = strtok(s, " ");

    while (plvrTpm != NULL)
    {
        if (strcmp(plvrTpm, "teclado") != 0)
        {
            strcat(str2, plvrTpm);
            strcat(str2, " ");
        }
        else
        {
            strcat(str2, "teclado e mouse");
            strcat(str2, " ");
        }
        plvrTpm = strtok(NULL, " ");
    }

    if (str2[0] != '\0')
        str2[strlen(str2) - 1] = '\0';

    printf("%s", str2);
}

int main()

{

    char s[128] = "";

    printf("Digite uma sequencia de caracteres: ");
    fgets(s, sizeof(s), stdin);

    tcldRplc(s);

    // ctdFrq(s);
}