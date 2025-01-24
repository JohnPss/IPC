#pragma once
#include "Modulo.hpp"

class ModuloSeguranca : public Modulo
{
public:
    ModuloSeguranca(char tipo);
    bool podeAcessar() override;
};