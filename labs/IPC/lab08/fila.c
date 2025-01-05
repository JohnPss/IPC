#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila *criar_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    if (f == NULL)
    {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

No *criarNode(char *nome, int cpf, int prioridade)
{
    No *novoNode = (No *)malloc(sizeof(No));
    strcpy(novoNode->dado.nome, nome);
    novoNode->dado.cpf = cpf;
    novoNode->prioridade = prioridade;
    novoNode->prox = NULL;
    return novoNode;
}

void enfileira(Fila *fila, char nome[50], int cpf, int prioridade)
{
    No *novoNode = criarNode(nome, cpf, prioridade);

    if (fila_vazia(fila))
    {
        fila->inicio = novoNode;
        fila->fim = novoNode;
    }
    else if (prioridade == 1)
    {

        if (fila->inicio->prioridade == 0)
        {

            novoNode->prox = fila->inicio;
            fila->inicio = novoNode;
        }
        else
        {

            No *temp = fila->inicio;
            while (temp->prox != NULL && temp->prox->prioridade == 1)
            {
                temp = temp->prox;
            }
            novoNode->prox = temp->prox;
            temp->prox = novoNode;

            if (novoNode->prox == NULL)
            {
                fila->fim = novoNode;
            }
        }
    }
    else
    {

        fila->fim->prox = novoNode;
        fila->fim = novoNode;
    }
}

int contarFila(Fila *f, int prioridade)
{
    int count = 0;
    No *aux = f->inicio;

    while (aux != NULL)
    {
        if (prioridade == 1 && aux->prioridade == 1)
        {
            count++;
        }
        else if (prioridade == 0)
        {
            count++;
        }

        aux = aux->prox;
    }

    return count;
}

Pessoa desenfileirar(Fila *f)
{
    if (f != NULL && !fila_vazia(f))
    {
        No *aux = f->inicio;
        Pessoa dado = aux->dado;
        f->inicio = f->inicio->prox;
        free(aux);

        if (fila_vazia(f))
        {
            f->fim = NULL;
        }

        return dado;
    }
    else
    {
        printf("Fila inexistente ou vazia.\n");
    }
}

void mostrar_fila(Fila *f)
{
    if (f != NULL && !fila_vazia(f))
    {
        No *aux = f->inicio;
        int i = 1;
        printf("Fila: \n");
        while (aux != NULL)
        {
            printf("Pessoa %d:\n", i);
            printf("Nome: %s", aux->dado.nome);
            printf("CPF: %d \n", aux->dado.cpf);
            printf("\n");
            aux = aux->prox;
            i++;
        }

        printf("\n");
    }
    else
    {
        printf("Fila inexistente ou vazia.\n");
    }
}

int fila_vazia(Fila *f)
{
    if (f != NULL)
    {
        return f->inicio == NULL;
    }
    else
    {
        return -1;
    }
}

void liberar_fila(Fila *f)
{
    if (f != NULL)
    {
        No *aux;

        while (f->inicio != NULL)
        {
            aux = f->inicio;
            f->inicio = f->inicio->prox;
            free(aux);
        }

        free(f);
    }
}
