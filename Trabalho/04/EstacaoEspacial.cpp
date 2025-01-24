#include "EstacaoEspacial.hpp"

EstacaoEspacial::EstacaoEspacial(int linhas, int colunas)
{
    this->linhas = linhas;
    this->colunas = colunas;
    this->matriz = new Modulo *[linhas];
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = new Modulo[colunas];
    }
}
void EstacaoEspacial::adicionarModulo(int x, int y, char tipo)
{
    if (x < 0 || x >= getLinhas() || y < 0 || y >= getColunas())
    {
        std::cout << "Fora da nave" << std::endl;
    }
    else if (tipo == 'N')
    {
        this->matriz[x][y] = ModuloNormal(tipo);
    }
    else if (tipo == 'O')
    {
        this->matriz[x][y] = ModuloObstaculo(tipo);
    }
    else if (tipo == 'V')
    {
        this->matriz[x][y] = ModuloVazio(tipo);
    }
    else if (tipo == 'S')
    {
        this->matriz[x][y] = ModuloSeguranca(tipo);
    }
    else if (tipo == 'F')
    {
        this->matriz[x][y] = ModuloComFogo(tipo);
    }
    else if (tipo == 'A')
    {
        this->matriz[x][y] = ModuloComAstronauta(tipo);
    }
}
void EstacaoEspacial::adicionarAstronauta(Astronauta astronauta)
{
    this->astronautas.push_back(astronauta);
}

Modulo **EstacaoEspacial::getMatriz()
{
    return this->matriz;
}

std::vector<Astronauta> EstacaoEspacial::getAstronautas()
{
    return this->astronautas;
}

int EstacaoEspacial::getColunas()
{
    return this->colunas;
}

int EstacaoEspacial::getLinhas()
{
    return this->linhas;
}

EstacaoEspacial::~EstacaoEspacial()
{
    for (int i = 0; i < linhas; ++i)
    {
        delete[] this->matriz[i];
    }
    delete[] this->matriz;
}