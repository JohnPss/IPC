#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "caixa.h"

Caixa caixas[MAX_CAIXAS];

void cadastrarClienteOrdenado(int caixaId, const char *nome, long long cpf, int prioridade, int numItens)
{
    if (caixaId < 0 || caixaId >= MAX_CAIXAS)
    {
        printf("Id inválido.\n");
        return;
    }

    if (caixas[caixaId].tamanhoFila == MAX_CLIENTES)
    {
        printf("Fila do caixa %d está cheia.\n", caixaId + 1);
        return;
    }

    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    if (cliente == NULL)
    {
        printf("Falha ao alocar memória para o cliente.\n");
        return;
    }

    strcpy(cliente->nome, nome);
    cliente->cpf = cpf;
    cliente->prioridade = prioridade;
    cliente->numItens = numItens;

    int pos = caixas[caixaId].tamanhoFila;
    while (pos > 0 && caixas[caixaId].fila[pos - 1]->prioridade > prioridade)
    {
        caixas[caixaId].fila[pos] = caixas[caixaId].fila[pos - 1];
        pos--;
    }

    caixas[caixaId].fila[pos] = cliente;
    caixas[caixaId].tamanhoFila++;
}

void atenderCliente(int caixaId)
{
    if (caixaId < 0 || caixaId >= MAX_CAIXAS)
    {
        printf("\nID inválido.\n");
        return;
    }

    if (caixas[caixaId].tamanhoFila == 0)
    {
        printf("\nCaixa %d está vazia.\n", caixaId + 1);
        return;
    }

    Cliente *cliente = caixas[caixaId].fila[0];
    printf("\nAtendendo cliente %s (CPF: %lld) no caixa %d.\n", cliente->nome, cliente->cpf, caixaId + 1);

    free(cliente);

    for (int i = 1; i < caixas[caixaId].tamanhoFila; i++)
    {
        caixas[caixaId].fila[i - 1] = caixas[caixaId].fila[i];
    }

    caixas[caixaId].tamanhoFila--;
}

void abrirCaixa(int caixaId)
{
    if (caixaId < 0 || caixaId >= MAX_CAIXAS)
    {
        printf("\nID inválido.\n");
        return;
    }

    if (caixas[caixaId].aberto)
    {
        printf("\nCaixa %d já está aberto.\n", caixaId + 1);
        return;
    }

    caixas[caixaId].aberto = true;
    printf("\nCaixa %d aberto.\n", caixaId + 1);
}

void abrirCaixas()
{
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        caixas[i].aberto = true;
    }

    printf("\nTodos os caixas abertos.\n");
}

void fecharCaixa(int caixaId)
{
    if (caixaId < 0 || caixaId >= MAX_CAIXAS)
    {
        printf("ID inválido.\n");
        return;
    }

    if (!caixas[caixaId].aberto)
    {
        printf("Caixa %d já está fechado.\n", caixaId + 1);
        return;
    }

    int num_clientes = caixas[caixaId].tamanhoFila;

    for (int i = 0; i < num_clientes; i++)
    {

        int menorFila = -1;
        int minTam = MAX_CLIENTES + 1;

        for (int j = 0; j < MAX_CAIXAS; j++)
        {
            if (j != caixaId && caixas[j].aberto && caixas[j].tamanhoFila < minTam)
            {
                minTam = caixas[j].tamanhoFila;
                menorFila = j;
            }
        }

        if (menorFila != -1)
        {
            caixas[menorFila].fila[caixas[menorFila].tamanhoFila] = caixas[caixaId].fila[i];
            caixas[menorFila].tamanhoFila++;
        }
    }

    caixas[caixaId].tamanhoFila = 0;
    caixas[caixaId].aberto = false;
    printf("Caixa %d fechado.\n", caixaId + 1);
}

void imprimirListaClientesEspera()
{
    printf("\n");
    printf("Lista de Clientes em Espera:\n");
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        printf("Caixa %d: %s\n", i + 1, caixas[i].aberto ? "" : "(caixa fechado)");
        if (caixas[i].aberto)
        {
            for (int j = 0; j < caixas[i].tamanhoFila; j++)
            {
                Cliente *cliente = caixas[i].fila[j];
                printf("  Nome: %s (CPF: %lld, prioridade: %d, itens: %d)\n", cliente->nome, cliente->cpf, cliente->prioridade, cliente->numItens);
            }
        }
    }
}

void imprimirStatusCaixas()
{
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        printf("Caixa %d: %s, %d clientes em espera\n", i + 1, caixas[i].aberto ? "aberto" : "fechado", caixas[i].tamanhoFila);
    }
}
