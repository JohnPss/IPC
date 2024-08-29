#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include "autores.h"

typedef struct documento
{
    int id;
    char titulo[50];
    LSE *autores;
} Documento;

typedef struct nodop
{
    Documento doc;
    struct nodop *prox;
} NodoP;

typedef struct pilha
{
    NodoP *topo;
} Pilha;

void criarPilha(Pilha *pilha);
void empilhar(Pilha *pilha, Documento *doc);
void desempilhar(Pilha *pilha);
int mostrarTopo(Pilha *pilha);
int estaVazia(Pilha *pilha);

#endif