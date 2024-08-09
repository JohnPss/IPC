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
        printf("Nome: %s", p->nome);
        printf("CPF: %lld\t", p->cpf);
        printf("\n\n");
    }
    printf("\n");
}

void mostraespecifico(struct ListaSimplesEnc *pList, int cpf)
{
    struct Node *p;
    for (p = pList->prim; p != NULL; p = p->prox)
    {
        printf("Nome: %s", p->nome);
        printf("CPF: %lld\t", p->cpf);
        printf("\n\n");
    }
    printf("\n");
}

void inserirIni(struct ListaSimplesEnc *pList, int cpf, char nome[50])
{
    struct Nodo *novo;
    novo = (struct Nodo *)malloc(sizeof(struct Nodo));
    novo->cpf = cpf;
    strcpy(novo->nome, nome);
    novo->prox = pList->prim;
    pList->prim = novo;
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