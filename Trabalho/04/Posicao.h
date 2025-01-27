// Arquivo: Posicao.h
#ifndef POSICAO_H
#define POSICAO_H

struct Posicao
{
    int linha;
    int coluna;

    // Construtores
    Posicao() : linha(0), coluna(0) {}
    Posicao(int l, int c) : linha(l), coluna(c) {}

    // Métodos úteis
    bool operator==(const Posicao &outras) const
    {
        return linha == outras.linha && coluna == outras.coluna;
    }

    int distancia(const Posicao &outra) const
    {
        return std::abs(linha - outra.linha) + std::abs(coluna - outra.coluna);
    }
};

#endif // POSICAO_H