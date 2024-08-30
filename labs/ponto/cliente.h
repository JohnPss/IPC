#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente
{
    char nome[50];
    long int CPF[11];
    int prioriade;
    int numItens;

} Cliente;

typedef struct nodo
{

    struct nodo *prox;
} Nodo;

typedef struct filacliente
{

} FilaCliente;

void addNodo(Nodo *nod);

#endif CLIENTE_H