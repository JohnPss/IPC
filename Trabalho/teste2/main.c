#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "caixa.h"

int main()
{

    abrirCaixas();
    int opcao;

    do
    {
        printf("Menu de Opções:\n");
        printf("1. Cadastrar cliente. \n");
        printf("2. Atender um Cliente\n");
        printf("3. Abrir caixa \n");
        printf("4. Fechar caixa \n");
        printf("5. Imprimir a Lista de Clientes em Espera\n");
        printf("6. Imprimir o Status dos Caixas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        printf("\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            int caixa_id;
            char nome[100];
            long long cpf;
            int prioridade;
            int num_itens;

            do
            {
                printf("Digite o ID do caixa: ");
                scanf("%d", &caixa_id);
                while (getchar() != '\n')
                    ; // Limpar buffer

                if (!caixas[caixa_id - 1].aberto)
                {
                    printf("Caixa %d está fechado. Por favor, digite outro ID de caixa.\n", caixa_id - 1);
                }
            } while (!caixas[caixa_id - 1].aberto);

            printf("Digite o nome do cliente: ");
            scanf("%s", nome);
            while (getchar() != '\n')
                ; // Limpar buffer

            printf("Digite o CPF do cliente: ");
            scanf("%lld", &cpf);
            while (getchar() != '\n')
                ; // Limpar buffer

            printf("Digite a prioridade do cliente: ");
            scanf("%d", &prioridade);
            while (getchar() != '\n')
                ; // Limpar buffer

            printf("Digite o número de itens do cliente: ");
            scanf("%d", &num_itens);
            while (getchar() != '\n')
                ; // Limpar buffer

            cadastrarClienteOrdenado(caixa_id - 1, nome, cpf, prioridade, num_itens);

            break;
        case 2:

            printf("Qual caixa deseja atentar? \n");
            scanf("%d", &caixa_id);
            atenderCliente(caixa_id - 1);

            break;
        case 3:
            printf("Digite o ID do caixa que deseja abrir: ");
            scanf("%d", &caixa_id);
            while (getchar() != '\n')
                ; // Limpar buffer
            abrirCaixa(caixa_id - 1);

            break;

        case 4:
            printf("Digite o ID do caixa que deseja fechar: ");
            scanf("%d", &caixa_id);
            while (getchar() != '\n')
                ; // Limpar buffer
            fecharCaixa(caixa_id - 1);

        case 5:
            imprimirListaClientesEspera();
            break;

        case 6:
            imprimirStatusCaixas();
            break;

        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}