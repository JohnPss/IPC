#include <stdio.h>
#include "fila.h"

int main()
{
    Fila *f = criar_fila(); // Cria uma fila vazia
    int opcao, dado;        // Variáveis para armazenar a opção do menu e o dado a ser inserido ou removido

    do
    {
        printf("Escolha uma opção:\n");
        printf("1 - Inserir na fila\n");
        printf("2 - Remover da fila\n");
        printf("3 - Imprimir a fila\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Inserir na fila
            printf("Digite o dado a ser inserido: ");
            scanf("%d", &dado);
            enfileirar(f, dado);
            break;
        case 2: // Remover da fila
            dado = desenfileirar(f);
            if (dado != -1)
            {
                printf("Dado removido: %d\n", dado);
            }
            break;
        case 3: // Imprimir a fila
            mostrar_fila(f);
            break;
        case 0: // Sair
            break;
        default: // Opção inválida
            printf("Opção inválida.\n");
            break;
        }
    } while (opcao != 0);

    liberar_fila(f); // Libera a memória da fila

    return 0;
}