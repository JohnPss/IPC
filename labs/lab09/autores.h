#ifndef AUTORES_H
#define AUTORES_H

typedef struct autor
{
    char nome[50];
    int id;
} Autor;

typedef struct nodoF
{
    Autor autor;
    struct nodoF *prox;
} NodoF;

typedef struct lse
{
    NodoF *prim;
} LSE;

void criarLSE();
void addLista(LSE *l, Autor *p);
void mostrarLSE(LSE *l);

#endif