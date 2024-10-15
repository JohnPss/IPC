#ifndef CAIXA_H
#define CAIXA_H

#include <stdbool.h>

#define MAX_NOME 100
#define MAX_CAIXAS 5
#define MAX_CLIENTES 30

typedef struct
{
    char nome[MAX_NOME];
    long long cpf;
    int prioridade;
    int numItens;
} Cliente;

typedef struct
{
    int id;
    bool aberto;
    Cliente *fila[MAX_CLIENTES];
    int tamanhoFila;
} Caixa;

extern Caixa caixas[MAX_CAIXAS];

void cadastrarClienteOrdenado(int caixaId, const char *nome, long long cpf, int prioridade, int numItens);
void atenderCliente(int caixaId);
void abrirCaixa(int caixaId);
void abrirCaixas();
void fecharCaixa(int caixaId);
void imprimirListaClientesEspera();
void imprimirStatusCaixas();

#endif // CAIXA_H