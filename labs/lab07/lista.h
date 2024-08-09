#ifndef LISTA_H
#define LISTA_H
struct Nodo
{
    char nome[50];
    long long cpf;
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
void inserirIni(struct ListaSimplesEnc *pList, int cpf, char nome[50]);
void removerIni(struct ListaSimplesEnc *pList);
int estaVazia(struct ListaSimplesEnc *pList);
#endif