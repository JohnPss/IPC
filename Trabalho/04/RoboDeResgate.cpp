#include "RoboDeResgate.hpp"

RoboDeResgate::RoboDeResgate(int x, int y, EstacaoEspacial estacao)
{
    this->posicaoInicialX = x;
    this->posicaoInicialY = y;
    this->estacao = estacao;
    this->passos = 0;
    this->resgatados = std::vector<Astronauta>();
    this->naoResgatados = estacao.getAstronautas();

    this->visitados = new bool *[estacao.getLinhas()];
    this->distancia = new int *[estacao.getLinhas()];
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        visitados[i] = new bool[estacao.getColunas()];
        distancia[i] = new int[estacao.getColunas()];
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            visitados[i][j] = false;
            distancia[i][j] = -1;
        }
    }
};

void RoboDeResgate::iniciarResgate() {
};

void RoboDeResgate::calcularDistancia(int x, int y) {

};

bool RoboDeResgate::proximoAoFogo(int x, int y)
{
    if (x + 1 < estacao.getColunas() && estacao.getMatriz()[x + 1][y].getTipo() == 'F')
    {
        return true;
    }

    if (x - 1 >= 0 && estacao.getMatriz()[x - 1][y].getTipo() == 'F')
    {
        return true;
    }

    if (y + 1 < estacao.getLinhas() && estacao.getMatriz()[x][y + 1].getTipo() == 'F')
    {
        return true;
    }

    if (y - 1 >= 0 && estacao.getMatriz()[x][y - 1].getTipo() == 'F')
    {
        return true;
    }

    return false;
};

bool RoboDeResgate::resgatarAstronauta(Astronauta a, int i)
{
    resgatados.push_back(a);
    auto it = std::find(naoResgatados.begin(), naoResgatados.end(), a);
    if (it != naoResgatados.end())
    {
        naoResgatados.erase(it);
    }
    return true;
};

void RoboDeResgate::gerarRelatorio() {

};

void RoboDeResgate::gerarRelatorio(std::any obj) {

};
