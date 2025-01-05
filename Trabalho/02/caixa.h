#ifndef CAIXA_H
#define CAIXA_H

#include <stdbool.h>

#define MAX_NOME 100
#define MAX_CAIXAS 5

typedef struct
{
    char nome[MAX_NOME];
    long long cpf;
    int prioridade;
    int num_itens;
} Cliente;

typedef struct
{
    int id;
    bool aberto;
    Cliente *fila[MAX_CAIXAS];
    int tamanho_fila;
} Caixa;

void iniciarCaixa(Caixa caixas[MAX_CAIXAS]);
void abrirCaixa(Caixa *caixa);
void fecharCaixa(Caixa *caixa, Caixa caixas[MAX_CAIXAS]);
void realocarClientes(Caixa *caixa_fechado, Caixa caixas[MAX_CAIXAS]);
void listarClientes(Caixa caixas[MAX_CAIXAS]);

void listarClientesPorCaixa(Caixa caixas[MAX_CAIXAS]);
void cadrastrarClntPrrde(Caixa *caixa, Cliente *cliente);
void cadastrarCliente(Caixa *caixa, Cliente *cliente);
Cliente *remover_cliente(Caixa *caixa);
void ordenar_fila_por_prioridade(Caixa *caixa);

#endif // CAIXA_H