#pragma once
#include "Modulo.hpp"
#include "Astronauta.hpp"
#include "EstacaoEspacial.hpp"
#include "ModuloNormal.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloVazio.hpp"
#include "ModuloSeguranca.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloComAstronauta.hpp"
#include <vector>
#include <iostream>

class EstacaoEspacial
{
private:
    Modulo **matriz;
    std::vector<Astronauta> astronautas;
    int linhas;
    int colunas;

public:
    EstacaoEspacial();
    EstacaoEspacial(int linhas, int colunas);
    void adicionarModulo(int x, int y, char tipo);
    void adicionarAstronauta(Astronauta astronauta);
    Modulo **getMatriz();
    std::vector<Astronauta> getAstronautas();
    int getColunas();
    int getLinhas();
    const std::vector<Astronauta> &getAstronautas() const;
};