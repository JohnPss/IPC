#include "RoboDeResgate.hpp"
#include <queue>
RoboDeResgate::RoboDeResgate(EstacaoEspacial &estacao) : estacao(estacao)
{
    Posicao moduloSeguranca = iniciarResgate();
    posicaoInicialX = moduloSeguranca.coluna;
    posicaoInicialY = moduloSeguranca.linha;
    passos = 0;
    resgatados = std::vector<Astronauta>();
    naoResgatados = estacao.getAstronautas();

    visitados = std::vector<std::vector<bool>>(estacao.getLinhas(), std::vector<bool>(estacao.getColunas(), false));
    distancia = std::vector<std::vector<int>>(estacao.getLinhas(), std::vector<int>(estacao.getColunas(), -1));
}

Posicao RoboDeResgate::iniciarResgate()
{
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            if (estacao.getMatriz()[i][j].getTipo() == 'S')
            {
                return {i, j};
            }
        }
    }
    throw std::runtime_error("Módulo de segurança não encontrado");
}

std::vector<std::vector<int>> RoboDeResgate::calcularDistancia(int x_inicio, int y_inicio)
{
    std::queue<std::pair<int, int>> fila;
    std::vector<std::vector<int>> distancia(estacao.getLinhas(), std::vector<int>(estacao.getColunas(), -1));

    std::vector<std::pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    fila.push({x_inicio, y_inicio});
    distancia[x_inicio][y_inicio] = 0;

    while (!fila.empty())
    {
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();

        for (auto &direcao : direcoes)
        {
            int novo_x = x + direcao.first;
            int novo_y = y + direcao.second;

            if (novo_x < 0 || novo_x >= estacao.getLinhas() || novo_y < 0 || novo_y >= estacao.getColunas())
            {
                continue;
            }

            char tipoModulo = estacao.getMatriz()[novo_x][novo_y].getTipo();
            if (tipoModulo == '#' || tipoModulo == 'F' || tipoModulo == '~' || proximoAoFogo(novo_x, novo_y) || distancia[novo_x][novo_y] != -1)
            {
                continue;
            }

            distancia[novo_x][novo_y] = distancia[x][y] + 1;
            fila.push({novo_x, novo_y});
        }
    }

    return distancia;
}

int RoboDeResgate::calcularTotalPassos(const std::vector<std::vector<int>> &distancia)
{
    int totalPassos = 0;
    for (const auto &linha : distancia)
    {
        for (int d : linha)
        {
            if (d != -1)
            {
                totalPassos += d;
            }
        }
    }
    return totalPassos;
}

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

void RoboDeResgate ::resgatarAstronauta(int x, int y)
{
    if (estacao.getMatriz()[x][y].getTipo() == 'A')

    {
        for (int i = 0; i < estacao.getAstronautas().size(); i++)
        {
            if (estacao.getAstronautas()[i].getX() == x && estacao.getAstronautas()[i].getY() == y)
            {
                resgatados.push_back(estacao.getAstronautas()[i]);
                estacao.getAstronautas().erase(estacao.getAstronautas().begin() + i);
                // estacao.getMatriz()[x][y] = Modulo('N');
            }
        }
    }
}

void RoboDeResgate::gerarRelatorio()
{
    std::cout << "Astronautas resgatados: " << std::endl;
    for (auto astronauta : resgatados)
    {
        std::cout << astronauta.toString() << std::endl;
    }
    std::cout << "Astronautas nao resgatados: " << std::endl;
    for (auto astronauta : naoResgatados)
    {
        std::cout << astronauta.toString() << std::endl;
    }

    std::cout << "Passos necessarios:" << std::endl;
    std::cout << passos << std::endl;
};

void RoboDeResgate::gerarRelatorio(std::any obj)
{
    std::cout << std::any_cast<std::string>(obj) << std::endl;
};
