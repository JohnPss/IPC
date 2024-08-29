#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "autores.h"

void criarLSE(LSE *aL)
{
    aL->prim = NULL;
}

void addLista(LSE *l, Autor *p)
{
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    novo->autor.id = p->id;
    strcpy(novo->autor.nome, p->nome);
    novo->prox = NULL;

    Nodo *temp = (Nodo *)malloc(sizeof(Nodo));
    temp = l->prim;

    if (l->prim == NULL)
    {
        l->prim = novo;
    }
    else
    {
        for (; !temp->prox; temp = temp->prox)
        {
        }
        temp->prox = novo;
    }
}

void mostrarLSE(LSE *l)
{
    Nodo *p;
    for (p = l->prim; p != NULL; p = p->prox)
    {
        printf("--------------");
        printf("Nome: %s\n", p->autor.nome);
        printf("ID: %d\n", p->autor.id);
        printf("\n");
    }
}