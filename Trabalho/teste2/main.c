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

            int caixaId;
            char nome[100];
            long long cpf;
            int prioridade;
            int numItens;

            do
            {
                printf("Digite o ID do caixa: ");
                scanf("%d", &caixaId);
                while (getchar() != '\n')
                    ;

                if (!caixas[caixaId - 1].aberto)
                {
                    printf("Caixa %d está fechado. Por favor, digite outro ID de caixa.\n", caixaId - 1);
                }
            } while (!caixas[caixaId - 1].aberto);

            printf("Digite o nome do cliente: ");
            scanf("%s", nome);
            while (getchar() != '\n')
                ;

            printf("Digite o CPF do cliente: ");
            scanf("%lld", &cpf);
            while (getchar() != '\n')
                ;

            do
            {
                printf("Digite a prioridade do cliente (1, 2 ou 3): ");
                scanf("%d", &prioridade);
                while (getchar() != '\n')
                    ;
                if (prioridade < 1 || prioridade > 3)
                {
                    printf("Prioridade inválida. Por favor, digite 1, 2 ou 3.\n");
                }
            } while (prioridade < 1 || prioridade > 3);

            cadastrarClienteOrdenado(caixaId - 1, nome, cpf, prioridade, numItens);

            break;
        case 2:

            printf("Qual caixa deseja atentar? \n");
            scanf("%d", &caixaId);
            atenderCliente(caixaId - 1);

            break;
        case 3:
            printf("Digite o ID do caixa que deseja abrir: ");
            scanf("%d", &caixaId);
            while (getchar() != '\n')
                ;
            abrirCaixa(caixaId - 1);

            break;

        case 4:
            printf("Digite o ID do caixa que deseja fechar: ");
            scanf("%d", &caixaId);
            while (getchar() != '\n')
                ;
            fecharCaixa(caixaId - 1);

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