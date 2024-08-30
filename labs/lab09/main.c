#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "autores.h"
#include "documento.h"
#include "binario.h"

int main()
{
    Pilha docs;
    Documento *doc;
    LSE autores;
    Autor *autor;
    doc = malloc(sizeof(Documento));
    autor = malloc(sizeof(Autor));
    if (doc == NULL || autor == NULL)
    {
        printf("Memória insuficiente.\n");
        return 1;
    }
    criarPilha(&docs);
    criarLSE(&autores);

    char arq[50] = "pilha.bin";

    int opcao;
    while (1)
    {
        printf("\n------------------\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Verificar se está vazia\n");
        printf("5 - Guardo no arquivo binario\n");
        printf("6 - Carregar pilha do arquivo binario\n");
        printf("7 - Sair\n");
        printf("Opção? ");
        scanf("%d", &opcao);
        printf("\n------------------\n");
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Qual o título do documento? ");
            fgets(doc->titulo, 50, stdin);
            doc->titulo[strcspn(doc->titulo, "\n")] = '\0'; // Remover o newline

            printf("Qual o ID do documento? ");
            scanf("%d", &doc->id);
            getchar();

            printf("Digite quantos autores deseja inserir: ");
            int numAutores;
            scanf("%d", &numAutores);
            getchar();

            for (int j = 0; j < numAutores; j++)
            {
                printf("Qual o nome do autor %d: ", j + 1);
                fgets(autor->nome, 50, stdin);
                autor->nome[strcspn(autor->nome, "\n")] = '\0';

                printf("Qual o ID do autor %d: ", j + 1);
                scanf("%d", &autor->id);
                getchar();

                addLista(&autores, autor);
            }

            doc->autores = autores.prim;

            empilhar(&docs, doc->id, doc->titulo, autores.prim);

            // empilhar(&docs, doc->id, &doc->titulo, &autores);
            printf("Digite quantos autores deseja inserir: ");

            break;
        case 2:
            desempilhar(&docs);
            break;
        case 3:
            mostrarTopo(&docs);
            break;
        case 4:
            if (estaVazia(&docs))
            {
                printf("A pilha está vazia.\n");
            }
            else
            {
                printf("A pilha não está vazia.\n");
            }
            break;
        case 5:
            salvarPilha(&docs, arq);
            break;

        case 6:
            carregarPilha(&docs, arq);
            break;
        case 7:
            exit(0);
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }

    free(doc);
    free(autor);

    return 0;
}
