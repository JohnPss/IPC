#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Cria uma fila vazia e retorna seu endereço
Fila *criar_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila)); // Aloca memória para a fila

    if (f == NULL)
    { // Verifica se a alocação foi bem sucedida
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    f->inicio = NULL; // Inicializa o início da fila como NULL
    f->fim = NULL;    // Inicializa o fim da fila como NULL

    return f; // Retorna o endereço da fila criada
}

// Insere um dado no fim da fila
void enfileirar(Fila *f, TipoDado dado)
{
    if (f != NULL)
    {                                        // Verifica se a fila existe
        No *novo = (No *)malloc(sizeof(No)); // Aloca memória para o novo nó

        if (novo == NULL)
        { // Verifica se a alocação foi bem sucedida
            printf("Erro na alocação de memória.\n");
            exit(1);
        }

        novo->dado = dado; // Atribui o dado ao novo nó
        novo->prox = NULL; // Atribui NULL ao ponteiro para o próximo nó do novo nó

        if (fila_vazia(f))
        { // Se a fila estiver vazia, o novo nó será o início e o fim da fila
            f->inicio = novo;
            f->fim = novo;
        }
        else
        { // Se a fila não estiver vazia, o novo nó será o próximo do fim da fila e o novo fim da fila
            f->fim->prox = novo;
            f->fim = novo;
        }
    }
}

// Remove um dado do início da fila e retorna seu valor
TipoDado desenfileirar(Fila *f)
{
    if (f != NULL && !fila_vazia(f))
    {                                // Verifica se a fila existe e não está vazia
        No *aux = f->inicio;         // Guarda o endereço do início da fila em aux
        TipoDado dado = aux->dado;   // Guarda o dado do início da fila em dado
        f->inicio = f->inicio->prox; // Atualiza o início da fila para o próximo nó
        free(aux);                   // Libera a memória do nó apontado por aux

        if (fila_vazia(f))
        { // Se a fila ficou vazia, o fim da fila também deve ser NULL
            f->fim = NULL;
        }

        return dado; // Retorna o dado removido
    }
    else
    { // Se a fila não existe ou está vazia, retorna um valor inválido
        printf("Fila inexistente ou vazia.\n");
        return -1;
    }
}

// Imprime os dados da fila na ordem do início ao fim
void mostrar_fila(Fila *f)
{
    if (f != NULL && !fila_vazia(f))
    {                        // Verifica se a fila existe e não está vazia
        No *aux = f->inicio; // Cria um ponteiro auxiliar para percorrer a fila

        printf("Fila: ");
        while (aux != NULL)
        {                             // Enquanto o auxiliar não for NULL
            printf("%d ", aux->dado); // Imprime o dado do nó apontado por aux
            aux = aux->prox;          // Atualiza o auxiliar para o próximo nó
        }

        printf("\n");
    }
    else
    { // Se a fila não existe ou está vazia, imprime uma mensagem de erro
        printf("Fila inexistente ou vazia.\n");
    }
}

// Verifica se a fila está vazia e retorna 1 se sim, 0 se não
int fila_vazia(Fila *f)
{
    if (f != NULL)
    {                             // Verifica se a fila existe
        return f->inicio == NULL; // Retorna 1 se o início da fila for NULL, 0 caso contrário
    }
    else
    { // Se a fila não existe, retorna -1
        return -1;
    }
}

// Libera a memória de uma fila e seus nós
void liberar_fila(Fila *f)
{
    if (f != NULL)
    {            // Verifica se a fila existe
        No *aux; // Cria um ponteiro auxiliar para percorrer a fila

        while (f->inicio != NULL)
        {                                // Enquanto o início da fila não for NULL
            aux = f->inicio;             // Guarda o endereço do início da fila em aux
            f->inicio = f->inicio->prox; // Atualiza o início da fila para o próximo nó
            free(aux);                   // Libera a memória do nó apontado por aux
        }

        free(f); // Libera a memória da fila
    }
}