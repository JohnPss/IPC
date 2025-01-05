#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    while (1)
    {
        struct ListaSimplesEnc minhaLista;
        int cpf, op, prioridade;
        char nome[50];

        criarLista(&minhaLista);

        while (1)
        {
            printf("\n1 - Inserir nova pessoa\n");
            printf("2 - Retirar pessoa\n");
            printf("3 - Imprimir todas as pessoas\n");
            printf("4 - Verificar se a lista está vazia\n");
            printf("5 - Sair\n");
            printf("Opcao? ");
            scanf(" %d", &op);
            getchar();

            switch (op)
            {
            case 1:
                printf("\nDigite um nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Qual o CPF? \n");
                scanf("%d", &cpf);

                printf("Qual a prioridade (0: normal, 1: urgente)? \n");
                while (1)
                {
                    scanf("%d", &prioridade);
                    if (prioridade == 0 || prioridade == 1)
                        break;
                    else
                        printf("Opção inválida. Digite novamente.\n");
                }

                inserirFim(&minhaLista, cpf, nome, prioridade);

                printf("Dados da pessoa:\n");
                mostraespecifico(&minhaLista, cpf);
                printf("Quantidade de pessoas na frente: %d\n", tamanhoPrioridade(&minhaLista, prioridade));
                break;

            case 2:
                int cpfR;
                printf("\nDigite o CPF da pessoa que deseja remover: ");
                scanf("%d", &cpfR);

                printf("Dados da pessoa removida:\n");
                mostraespecifico(&minhaLista, cpfR);

                remover(&minhaLista, cpfR);
                printf("Sobraram %d pessoas na lista!\n", tamanhoLista(&minhaLista));
                break;

            case 3:
                mostrarLista(&minhaLista);
                break;

            case 4:
                if (estaVazia(&minhaLista))
                    printf("Lista vazia\n");
                else
                    printf("A lista nao esta vazia!");
                break;

            case 5:
                exit(0);
                break;
            }
        }
    }

    return 0;
}