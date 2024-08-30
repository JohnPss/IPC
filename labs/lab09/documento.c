#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autores.h"
#include "documento.h"

void criarPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}

void empilhar(Pilha *p, int id, char *titulo, NodoF *autores)
{
    NodoP *novoDoc = (NodoP *)malloc(sizeof(NodoP));
    novoDoc->doc.id = id;
    strcpy(novoDoc->doc.titulo, titulo);
    novoDoc->doc.autores = autores;
    novoDoc->prox = p->topo;
    p->topo = novoDoc;
}

NodoP *desempilhar(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("A pilha está vazia.\n");
        return NULL;
    }
    NodoP *docRemovido = p->topo;
    p->topo = p->topo->prox;
    return docRemovido;
}
void mostrarTopo(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("A pilha está vazia.\n");
    }
    else
    {
        printf("Documento no topo:\nID: %d\nTítulo: %s\n", p->topo->doc.id, p->topo->doc.titulo);

        NodoF *atualF = p->topo->doc.autores;
        printf("Autores:\n");
        while (atualF != NULL)
        {
            printf("Autor ID: %d\n", atualF->autor.id);
            printf("Autor nome: %s\n", atualF->autor.nome);
            atualF = atualF->prox;
        }
    }
}

// void mostrarPilha(Pilha *pilha)
// {
//     if (estaVazia(pilha))
//     {
//         printf("Pilha vazia.\n");
//     }
//     else
//     {
//         NodoP *atual = pilha->topo;
//         printf("Conteúdo da pilha:\n");
//         while (atual != NULL)
//         {
//             printf("Documento ID: %d\n", atual->doc.id);
//             printf("Documento nome: %s\n", atual->doc.titulo);

//             NodoF *atualF = atual->doc.autores.prim;
//             while (atualF != NULL)
//             {
//                 printf("Autor ID: %d\n", atualF->autor.id);
//                 printf("Autor nome: %s\n", atualF->autor.nome);
//                 atualF = atualF->prox;
//             }

//             atual = atual->prox;
//         }
//     }
// }

int estaVazia(Pilha *pilha)
{
    return (pilha->topo == NULL);
}
