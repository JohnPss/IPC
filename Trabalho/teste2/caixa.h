#ifndef CAIXA_H
#define CAIXA_H

#include <stdbool.h>

#define MAX_NOME 100
#define MAX_CAIXAS 2
#define MAX_CLIENTES 30

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
    Cliente *fila[MAX_CLIENTES];
    int tamanho_fila;
} Caixa;

extern Caixa caixas[MAX_CAIXAS];

void cadastrarClienteOrdenado(int caixa_id, const char *nome, long long cpf, int prioridade, int num_itens);
void atenderCliente(int caixa_id);
void abrirCaixa(int caixa_id);
void abrirCaixas();
void fecharCaixa(int caixa_id);
void imprimirListaClientesEspera();
void imprimirStatusCaixas();

#endif // CAIXA_H