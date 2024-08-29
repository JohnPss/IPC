#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autores.h"
#include "documento.h"

void criarPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, Documento *doc)
{
    NodoP *novo = (NodoP *)malloc(sizeof(NodoP));
    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        return;
    }

    novo->doc = *doc;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void desempilhar(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("Pilha vazia.\n");
    }
    NodoP *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
}

int mostrarTopo(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return -1;
    }
}

int estaVazia(Pilha *pilha)
{
    return (pilha->topo == NULL);
}