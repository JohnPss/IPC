#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criarLista(struct ListaSimplesEnc *pList)
{
    pList->prim = NULL;
}
void mostrarLista(struct ListaSimplesEnc *pList)
{
    struct Nodo *p;
    for (p = pList->prim; p != NULL; p = p->prox)
    {
        if (p->prioridade == 1)
        {
            printf("Nome: %s   ", p->nome);
            printf("CPF: %lld\t", p->cpf);
            printf("\n\n");
        }
    }
    for (p = pList->prim; p != NULL; p = p->prox)
    {
        if (p->prioridade == 0)
        {
            printf("Nome: %s   ", p->nome);
            printf("CPF: %lld\t", p->cpf);
            printf("\n\n");
        }
    }
    printf("\n");
}

void mostraespecifico(struct ListaSimplesEnc *pList, int cpf)
{
    struct Nodo *p;
    for (p = pList->prim; p != NULL; p = p->prox)
    {
        if (p->cpf == cpf)
        {
            printf("Nome: %s\n", p->nome);
            printf("CPF: %lld\n", p->cpf);
        }
    }
}

void inserirIni(struct ListaSimplesEnc *pList, int cpf, char nome[50], int prioridade)
{
    struct Nodo *novo;
    novo = (struct Nodo *)malloc(sizeof(struct Nodo));
    novo->prioridade = prioridade;
    novo->cpf = cpf;
    strcpy(novo->nome, nome);
    novo->prox = pList->prim;
    pList->prim = novo;
}

void inserirFim(struct ListaSimplesEnc *pList, int cpf, char nome[50], int prioridade)
{
    struct Nodo *novo;
    novo = (struct Nodo *)malloc(sizeof(struct Nodo));
    novo->prioridade = prioridade;
    novo->cpf = cpf;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (pList->prim == NULL)
    {
        pList->prim = novo;
    }
    else
    {
        struct Nodo *p;
        for (p = pList->prim; p->prox != NULL; p = p->prox)
        {
        }
        p->prox = novo;
    }
}
void removerIni(struct ListaSimplesEnc *pList)
{
    struct Nodo *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
}
int estaVazia(struct ListaSimplesEnc *pList)
{
    return (pList->prim == NULL);
}
int tamanhoLista(struct ListaSimplesEnc *pList)
{
    int tamanho = 0;
    struct Nodo *p;
    for (p = pList->prim; p != NULL; p = p->prox)
    {
        tamanho++;
    }
    return tamanho;
}

int tamanhoPrioridade(struct ListaSimplesEnc *pList, int prioridade)
{
    int tamanho = 0;
    struct Nodo *p;
    for (p = pList->prim; p != NULL; p = p->prox)
    {
        if (prioridade == 1 && p->prioridade == 1)
        {
            tamanho++;
        }
        else if (prioridade == 0)
        {
            tamanho++;
        }
    }
    return tamanho;
}

void remover(struct ListaSimplesEnc *pList, int cpf)
{
    struct Nodo *atual, *anterior;

    atual = pList->prim;
    anterior = NULL;

    while (atual != NULL)
    {
        if (atual->cpf == cpf)
        {
            if (anterior == NULL)
            {
                pList->prim = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }
}