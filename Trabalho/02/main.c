#include "caixa.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Caixa caixas[MAX_CAIXAS];
    iniciarCaixa(caixas);
    int opcao;

    do
    {
        printf("1 - Abrir caixa\n");
        printf("2 - Fechar caixa\n");
        printf("3 - Cadastrar cliente\n");
        printf("4 - Listar clientes\n");
        printf("5 - Listar clientes por caixa\n");
        printf("6 - Sair\n");

        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            for (int i = 0; i < MAX_CAIXAS; i++)
            {
                if (!caixas[i].aberto)
                {
                    abrirCaixa(&caixas[i]);
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0; i < MAX_CAIXAS; i++)
            {
                if (caixas[i].aberto)
                {
                    fecharCaixa(&caixas[i], caixas);
                    break;
                }
            }
            break;
        case 3:
            Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
            printf("Digite o nome do cliente: ");
            fgets(cliente->nome, MAX_NOME, stdin);
            cliente->nome[strcspn(cliente->nome, "\n")] = '\0'; // Remove newline character

            printf("Digite o cpf do cliente: ");
            scanf("%lld", &cliente->cpf);
            while (getchar() != '\n')
                ; // Clear input buffer

            printf("Digite a prioridade do cliente: ");
            scanf("%d", &cliente->prioridade);
            while (getchar() != '\n')
                ; // Clear input buffer

            printf("Digite o numero de itens do cliente: ");
            scanf("%d", &cliente->num_itens);
            while (getchar() != '\n')
                ; // Clear input buffer

            for (int i = 0; i < MAX_CAIXAS; i++)
            {
                if (caixas[i].aberto)
                {
                    cadastrarCliente(&caixas[i], cliente);
                    break;
                }
            }
            break;
        case 4:
            listarClientes(caixas);
            break;
        case 5:
            listarClientesPorCaixa(caixas);
            break;
        case 6:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 6);

    return 0;
}