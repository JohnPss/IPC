#pragma once
#include "Modulo.hpp"
#include <iostream>

class ModuloComAstronauta : public Modulo
{
public:
    ModuloComAstronauta(char tipo);
    bool podeAcessar() override;
};