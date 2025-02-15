#pragma once
#include "Modulo.hpp"
#include "Astronauta.hpp"
#include "EstacaoEspacial.hpp"
#include "ModuloNormal.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloVazio.hpp"
#include "ModuloSeguranca.hpp"
#include "ModuloComFogo.hpp"
#include "Posicao.h"
#include "ModuloComAstronauta.hpp"
#include <vector>
#include <iostream>

class EstacaoEspacial
{
private:
    std::vector<std::vector<Modulo>> matriz;
    std::vector<Astronauta> astronautas;
    int linhas;
    int colunas;

public:
    EstacaoEspacial() = default;
    EstacaoEspacial(int linhas, int colunas);
    void adicionarModulo(size_t x, size_t y, char tipo);
    void adicionarAstronauta(Astronauta astronauta);
    const std::vector<std::vector<Modulo>> &getMatriz() const { return matriz; }
    std::vector<Astronauta> getAstronautas();
    size_t getLinhas() const;
    size_t getColunas() const;
    ~EstacaoEspacial();
    const std::vector<Astronauta> &getAstronautas() const;
    void carregarDoArquivo(std::ifstream &arquivo);
    void matrizCharToModulo(const std::vector<std::vector<char>> &matrizChar);
    void exbirMatriz();
    void exibirAstronautas();
};