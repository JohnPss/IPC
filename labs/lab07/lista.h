#ifndef LISTA_H
#define LISTA_H
struct Nodo
{
    char nome[50];
    long long cpf;
    int prioridade;
    struct Nodo *prox;
};

struct ListaSimplesEnc
{
    struct Nodo *prim;
};

typedef struct p
{
    struct Nodo *prox;
} pessoa;

void criarLista(struct ListaSimplesEnc *pList);
void mostrarLista(struct ListaSimplesEnc *pList);
void mostraespecifico(struct ListaSimplesEnc *pList, int cpf);
void inserirIni(struct ListaSimplesEnc *pList, int cpf, char nome[50], int prioridade);
void inserirFim(struct ListaSimplesEnc *pList, int cpf, char nome[50], int prioridade);
void removerIni(struct ListaSimplesEnc *pList);
int estaVazia(struct ListaSimplesEnc *pList);
int tamanhoLista(struct ListaSimplesEnc *pList);
int tamanhoPrioridade(struct ListaSimplesEnc *pList, int prioridade);
void remover(struct ListaSimplesEnc *pList, int cpf);
#endif