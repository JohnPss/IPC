#pragma once
#include "Modulo.hpp"

class ModuloNormal : public Modulo
{

public:
    ModuloNormal(char tipo);
    bool podeAcessar() override;
};