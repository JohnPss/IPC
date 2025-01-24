#pragma once
#include "EstacaoEspacial.hpp"
#include <vector>
#include <any>

class RoboDeResgate
{
private:
    int posicaoInicialX;
    int posicaoInicialY;
    EstacaoEspacial estacao;
    std::vector<Astronauta> resgatados;
    std::vector<Astronauta> naoResgatados;
    int passos;
    bool **visitados;
    int **distancia;

public:
    RoboDeResgate(int x, int y, EstacaoEspacial estacao);
    void iniciarResgate();
    void calcularDistancia(int x, int y);
    bool proximoAoFogo(int x, int y);
    bool resgatarAstronauta(Astronauta a, int i);
    void gerarRelatorio();
    void gerarRelatorio(std::any obj);
};