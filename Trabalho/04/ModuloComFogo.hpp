#pragma once
#include <iostream>
#include "Modulo.hpp"

class ModuloComFogo : public Modulo
{

public:
    ModuloComFogo(char tipo);
    bool podeAcessar() override;
};