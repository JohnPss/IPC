#include <stdio.h>
#include "fila.h"

int main()
{
    Fila *f = criar_fila();
    Pessoa dado;
    int opcao, prioridade;

    do
    {
        printf("\n");
        printf("Escolha uma opção:\n");
        printf("1 - Inserir uma nova pessoa!\n");
        printf("2 - Remover pessoa da fila\n");
        printf("3 - Imprimir a fila\n");
        printf("0 - Sair\n");
        scanf(" %d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Digite o nome da pessoa: ");
            fgets(dado.nome, 50, stdin);
            printf("Digite o cpf da pessoa: ");
            scanf("%d", &dado.cpf);
            printf("Digite a prioridade desta pessoa: ");
            scanf("%d", &prioridade);
            enfileira(f, dado.nome, dado.cpf, prioridade);
            break;
        case 2:
            dado = desenfileirar(f);
            if (dado.cpf != 0)
            {
                printf("Dado removido: %d\n", dado.cpf);
            }
            break;
        case 3:
            mostrar_fila(f);
            break;
        case 0:
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (opcao != 0);

    liberar_fila(f);

    return 0;
}