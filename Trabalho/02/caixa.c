#include "caixa.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void iniciarCaixa(Caixa caixas[MAX_CAIXAS])
{
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        caixas[i].id = i + 1;
        caixas[i].aberto = false;
        caixas[i].tamanho_fila = 0;
    }
}

void abrirCaixa(Caixa *caixa)
{
    caixa->aberto = true;
}

void abrirTodosCaixas(Caixa caixas[MAX_CAIXAS])
{
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        caixas[i].aberto = true;
    }
}

void fecharCaixa(Caixa *caixa, Caixa caixas[MAX_CAIXAS])
{
    caixa->aberto = false;
    realocarClientes(caixa, caixas);
}

void realocarClientes(Caixa *caixa_fechado, Caixa caixas[MAX_CAIXAS])
{
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        if (caixas[i].aberto)
        {
            for (int j = 0; j < caixas[i].tamanho_fila; j++)
            {
                caixas[i].fila[j] = caixa_fechado->fila[j];
            }
            caixas[i].tamanho_fila = caixa_fechado->tamanho_fila;
            break;
        }
    }
}

void listarClientes(Caixa caixas[MAX_CAIXAS])
{
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        if (caixas[i].aberto)
        {
            printf("Caixa %d:\n", caixas[i].id);
            for (int j = 0; j < caixas[i].tamanho_fila; j++)
            {
                printf("Cliente %d: %s\n", j + 1, caixas[i].fila[j]->nome);
            }
        }
    }
}

void listarClientesPorCaixa(Caixa caixas[MAX_CAIXAS])
{
    int id_caixa;
    printf("Digite o id do caixa: ");
    scanf("%d", &id_caixa);
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        if (caixas[i].id == id_caixa)
        {
            printf("Caixa %d:\n", caixas[i].id);
            for (int j = 0; j < caixas[i].tamanho_fila; j++)
            {
                printf("Cliente %d: %s\n", j + 1, caixas[i].fila[j]->nome);
            }
        }
    }
}

void cadrastrarClntPrrde(Caixa *caixa, Cliente *cliente)
{
    caixa->fila[caixa->tamanho_fila] = cliente;
    caixa->tamanho_fila++;
    ordenar_fila_por_prioridade(caixa);
}

void cadastrarCliente(Caixa *caixa, Cliente *cliente)
{
    caixa->fila[caixa->tamanho_fila] = cliente;
    caixa->tamanho_fila++;
}

Cliente *remover_cliente(Caixa *caixa)
{
    Cliente *cliente = caixa->fila[0];
    for (int i = 0; i < caixa->tamanho_fila - 1; i++)
    {
        caixa->fila[i] = caixa->fila[i + 1];
    }
    caixa->tamanho_fila--;
    return cliente;
}

void ordenar_fila_por_prioridade(Caixa *caixa)
{
    Cliente *aux;
    for (int i = 0; i < caixa->tamanho_fila; i++)
    {
        for (int j = i + 1; j < caixa->tamanho_fila; j++)
        {
            if (caixa->fila[i]->prioridade < caixa->fila[j]->prioridade)
            {
                aux = caixa->fila[i];
                caixa->fila[i] = caixa->fila[j];
                caixa->fila[j] = aux;
            }
        }
    }
}