#pragma once
#include "Modulo.hpp"

class ModuloObstaculo : public Modulo
{

public:
    ModuloObstaculo(char tipo);
    bool podeAcessar() override;
};