#pragma once
#include "EstacaoEspacial.hpp"
#include <vector>
#include <any>
#include <queue>
#include <climits>
#include <algorithm> // Adicionado para next_permutation
#include <bits/algorithmfwd.h>
#include <chrono>
#include <thread>

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
    bool isPosicaoValida(int x, int y);
    void moverRobo(Posicao inicio, Posicao fim);
    void imprimirCaminho(const std::vector<Posicao> &caminho);
    void imprimirMatriz(const Posicao &posicaoAtual);
    int calcularMenorCaminhoResgate();
    int calcularDistanciaEntrePontos(Posicao inicio, Posicao destino);
    bool proximoAoFogo(int x, int y);
    void resgatarAstronauta(int x, int y);
    void gerarRelatorio();
    void gerarRelatorio(std::any obj);
    std::vector<std::vector<bool>> &getVisitados() { return visitados; }
};