#include "Modulo.hpp"
#pragma once

class ModuloVazio : public Modulo
{
public:
    ModuloVazio(char tipo);
    bool podeAcessar() override;
};