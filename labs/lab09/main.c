#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "autores.h"
#include "documento.h"

int main()
{
    Pilha *docs;
    Documento *doc;
    LSE *autores;
    Autor *autor;
    doc = (Documento *)malloc(sizeof(Documento));
    autor = (Autor *)malloc(sizeof(Autor));
    if (doc == NULL || autor == NULL)
    {
        printf("Memória insuficiente.\n");
        return 1;
    }

    criarLSE(autores);
    criarPilha(docs);
    int opcao;
    while (1)
    {
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Verificar se está vazia\n");
        printf("5 - Sair\n");
        printf("Opção? ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            printf("Qual o titulo do documento?");
            fgets(doc->titulo, 50, stdin);

            printf("Qual o ID do documento?");
            scanf("%d", &doc->id);

            int i = 1;
            while (1)
            {
                printf("Qual o nome do autor %d:", i++);
                fgets(autor->nome, 50, stdin);
                printf("Qual o ID do autor %d:", i++);
                scanf("%d", &autor->id);
                doc->autores = autores;
            }

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            exit(0);
        }
    }
}
