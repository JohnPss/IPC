#pragma once
#include "EstacaoEspacial.hpp"
#include <vector>
#include <any>

class RoboDeResgate
{
private:
    int posicaoInicialX;
    int posicaoInicialY;
    int passos;
    EstacaoEspacial estacao;
    std::vector<Astronauta> resgatados;
    std::vector<Astronauta> naoResgatados;
    std::vector<std::vector<bool>> visitados;
    std::vector<std::vector<int>> distancia;

public:
    RoboDeResgate(EstacaoEspacial &estacao);
    Posicao iniciarResgate();
    std::vector<std::vector<int>> calcularDistancia(int x, int y);
    int calcularTotalPassos(const std::vector<std::vector<int>> &distancia);
    bool proximoAoFogo(int x, int y);
    void resgatarAstronauta(int x, int y);
    void gerarRelatorio();
    void gerarRelatorio(std::any obj);
    std::vector<std::vector<bool>> &getVisitados() { return visitados; }
};