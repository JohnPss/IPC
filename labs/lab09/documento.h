#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include "autores.h"

typedef struct documento
{
    int id;
    char titulo[50];
    LSE *autores;
} Documento;

typedef struct nodo
{
    Documento doc;
    Nodo *prox;
} Nodo;

typedef struct pilha
{
    Nodo *topo;
} Pilha;

void criarPilha(Pilha *pilha);
void empilhar(Pilha *pilha, Documento *doc);
int desempilhar(Pilha *pilha);
int mostrarTopo(Pilha *pilha);
int estaVazia(Pilha *pilha);

#endif