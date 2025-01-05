#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include "autores.h"

typedef struct documento
{
    int id;
    char titulo[50];
    NodoF *autores;
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
void empilhar(Pilha *p, int id, char *titulo, NodoF *autores);
NodoP *desempilhar(Pilha *p);
void mostrarTopo(Pilha *pilha);
void mostrarPilha(Pilha *pilha);
int estaVazia(Pilha *pilha);

#endif