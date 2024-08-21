#ifndef FILA_H
#define FILA_H

typedef struct pessoa
{
    char nome[50];
    int cpf;
} Pessoa;

typedef struct no
{
    Pessoa dado;
    int prioridade;
    struct no *prox;
} No;

typedef struct fila
{
    No *inicio;
    No *fim;
} Fila;

Fila *criar_fila();
void inserir(No **head, Pessoa *p, int prioridade);
void enfileira(Fila *fila, char nome[50], int cpf, int prioridade);
void mostrar_fila(Fila *f);
void liberar_fila(Fila *f);
int fila_vazia(Fila *f);
No *criarNode(char nome[50], int cpf, int prioridade);
Pessoa desenfileirar(Fila *f);

#endif