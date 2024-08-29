#ifndef AUTORES_H
#define AUTORES_H

typedef struct autor
{
    char nome[50];
    int id;
} Autor;

typedef struct nodo
{
    Autor autor;
    Nodo *prox;
} Nodo;

typedef struct lse
{
    Nodo *prim;
} LSE;

void criarLSE();
void addLista(LSE *l, Autor *p);
void mostrarLSE(LSE *l);

#endif