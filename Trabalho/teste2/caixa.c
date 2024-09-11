#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "caixa.h"

Caixa caixas[MAX_CAIXAS];

void cadastrarClienteOrdenado(int caixa_id, const char *nome, long long cpf, int prioridade, int num_itens)
{
    if (caixa_id < 0 || caixa_id >= MAX_CAIXAS)
    {
        printf("Id inválido.\n");
        return;
    }

    if (caixas[caixa_id].tamanho_fila == MAX_CLIENTES)
    {
        printf("Fila do caixa %d está cheia.\n", caixa_id + 1);
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
    cliente->num_itens = num_itens;

    int pos = caixas[caixa_id].tamanho_fila;
    while (pos > 0 && caixas[caixa_id].fila[pos - 1]->prioridade > prioridade)
    {
        caixas[caixa_id].fila[pos] = caixas[caixa_id].fila[pos - 1];
        pos--;
    }

    caixas[caixa_id].fila[pos] = cliente;
    caixas[caixa_id].tamanho_fila++;
}

void atenderCliente(int caixa_id)
{
    if (caixa_id < 0 || caixa_id >= MAX_CAIXAS)
    {
        printf("\nID inválido.\n");
        return;
    }

    if (caixas[caixa_id].tamanho_fila == 0)
    {
        printf("\\nCaixa %d está vazia.\n", caixa_id + 1);
        return;
    }

    Cliente *cliente = caixas[caixa_id].fila[0];
    printf("\nAtendendo cliente %s (CPF: %lld) no caixa %d.\n", cliente->nome, cliente->cpf, caixa_id + 1);

    free(cliente);

    for (int i = 1; i < caixas[caixa_id].tamanho_fila; i++)
    {
        caixas[caixa_id].fila[i - 1] = caixas[caixa_id].fila[i];
    }

    caixas[caixa_id].tamanho_fila--;
}

void abrirCaixa(int caixa_id)
{
    if (caixa_id < 0 || caixa_id >= MAX_CAIXAS)
    {
        printf("\nID inválido.\n");
        return;
    }

    if (caixas[caixa_id].aberto)
    {
        printf("\nCaixa %d já está aberto.\n", caixa_id + 1);
        return;
    }

    caixas[caixa_id].aberto = true;
    printf("\nCaixa %d aberto.\n", caixa_id + 1);
}

void abrirCaixas()
{
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        caixas[i].aberto = true;
    }

    printf("\nTodos os caixas abertos.\n");
}

void fecharCaixa(int caixa_id)
{
    if (caixa_id < 0 || caixa_id >= MAX_CAIXAS)
    {
        printf("ID inválido.\n");
        return;
    }

    if (!caixas[caixa_id].aberto)
    {
        printf("Caixa %d já está fechado.\n", caixa_id + 1);
        return;
    }

    int num_clientes = caixas[caixa_id].tamanho_fila;

    for (int i = 0; i < num_clientes; i++)
    {

        int min_fila_index = -1;
        int min_fila_size = MAX_CLIENTES + 1;

        for (int j = 0; j < MAX_CAIXAS; j++)
        {
            if (j != caixa_id && caixas[j].aberto && caixas[j].tamanho_fila < min_fila_size)
            {
                min_fila_size = caixas[j].tamanho_fila;
                min_fila_index = j;
            }
        }

        if (min_fila_index != -1)
        {
            caixas[min_fila_index].fila[caixas[min_fila_index].tamanho_fila] = caixas[caixa_id].fila[i];
            caixas[min_fila_index].tamanho_fila++;
        }
    }

    caixas[caixa_id].tamanho_fila = 0;
    caixas[caixa_id].aberto = false;
    printf("Caixa %d fechado.\n", caixa_id + 1);
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
            for (int j = 0; j < caixas[i].tamanho_fila; j++)
            {
                Cliente *cliente = caixas[i].fila[j];
                printf("  Nome: %s (CPF: %lld, prioridade: %d, itens: %d)\n", cliente->nome, cliente->cpf, cliente->prioridade, cliente->num_itens);
            }
        }
    }
}

void imprimirStatusCaixas()
{
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        printf("\nCaixa %d: %s\n", i + 1, caixas[i].aberto ? "aberto" : "fechado");
    }
}
