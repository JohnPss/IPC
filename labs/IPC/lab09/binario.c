#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binario.h"
#include "autores.h"
#include "documento.h"

void salvarPilha(Pilha *p, char nomeArquivo[50])
{
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    NodoP *atual = p->topo;
    while (atual != NULL)
    {
        fwrite(&(atual->doc.id), sizeof(int), 1, arquivo);
        fwrite(atual->doc.titulo, sizeof(char), 100, arquivo);

        NodoF *autorAtual = atual->doc.autores;
        while (autorAtual != NULL)
        {
            fwrite(&(autorAtual->autor.id), sizeof(int), 1, arquivo);
            fwrite(autorAtual->autor.nome, sizeof(char), 50, arquivo);
            autorAtual = autorAtual->prox;
        }

        int fimAutores = -1;
        fwrite(&fimAutores, sizeof(int), 1, arquivo);

        atual = atual->prox;
    }

    fclose(arquivo);
    printf("Pilha salva com sucesso em %s\n", nomeArquivo);
}

void carregarPilha(Pilha *p, char nomeArquivo[50])
{
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    criarPilha(p);
    NodoP *anterior = NULL;

    while (1)
    {
        NodoP *novoDoc = (NodoP *)malloc(sizeof(NodoP));
        if (!novoDoc)
        {
            printf("Erro ao alocar memória para novo documento.\n");
            break;
        }
        if (fread(&(novoDoc->doc.id), sizeof(int), 1, arquivo) != 1)
        {
            free(novoDoc);
            break;
        }
        fread(novoDoc->doc.titulo, sizeof(char), 100, arquivo);

        NodoF *ultimoAutor = NULL;
        while (1)
        {
            NodoF *novoAutor = (NodoF *)malloc(sizeof(NodoF));
            if (!novoAutor)
            {
                printf("Erro ao alocar memória para novo autor.\n");
                break;
            }
            fread(&(novoAutor->autor.id), sizeof(int), 1, arquivo);
            if (novoAutor->autor.id == -1)
            {
                free(novoAutor);
                break;
            }
            fread(novoAutor->autor.nome, sizeof(char), 50, arquivo);
            novoAutor->prox = NULL;

            if (ultimoAutor == NULL)
            {
                novoDoc->doc.autores = novoAutor;
            }
            else
            {
                ultimoAutor->prox = novoAutor;
            }
            ultimoAutor = novoAutor;
        }

        novoDoc->prox = NULL;
        if (anterior == NULL)
        {
            p->topo = novoDoc;
        }
        else
        {
            anterior->prox = novoDoc;
        }
        anterior = novoDoc;
    }

    fclose(arquivo);
    printf("Pilha carregada com sucesso de %s\n", nomeArquivo);
}