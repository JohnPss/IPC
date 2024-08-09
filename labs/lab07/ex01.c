#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int main()
{
    struct ListaSimplesEnc minhaLista;
    int cpf, op;
    char nome[50];
    criarLista(&minhaLista);
    while (1)
    {
        printf("1 - Inserir nova pessoa\n");
        printf("2 - Retirar pessoa\n");
        printf("3 - Imprimir todas as pessoas\n");
        printf("4 - Verificar se a lista está vazia\n");
        printf("5 - Mostrar lista\n");
        printf("6 - Sair\n");
        printf("Opcao? ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite um nome? ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            printf("Qual o cpf? ");
            scanf("%d", &cpf);
            inserirIni(&minhaLista, cpf, nome);
            printf("Dados da pessoa:\n");
            break;
        case 2:

            // scanf("%d", &valor);
            break;
        case 3: // remover o primeiro// TODO
            removerIni;
            break;
        case 4: // remover determinado elemento
            // TODO
            break;
        case 5: // mostrar lista
            if (estaVazia(&minhaLista))
                printf("lista vazia\n");
            else
                mostrarLista(&minhaLista);
            break;
        case 6: // abandonar o programa
            exit(0);
            break;
        }
        return 0;
    }
}