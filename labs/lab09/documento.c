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
    Nodo *novo = (struct Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        return;
    }

    novo->doc = doc;
    novo = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(struct Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return -1; // Retornar -1 ou outro valor específico quando a pilha está vazia.
    }
    int valor = pilha->topo->info;
    struct Nodo *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return valor;
}

int mostrarTopo(struct Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return -1;
    }
    return pilha->topo->info;
}

int estaVazia(struct Pilha *pilha)
{
    return (pilha->topo == NULL);
}