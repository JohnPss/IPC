#include "Modulo.hpp"
#include <iostream>

Modulo::Modulo()
{
}

Modulo::Modulo(char tipo)
{
    this->tipo = tipo;
}

char Modulo::getTipo() const
{
    return tipo;
}

bool Modulo::podeAcessar()
{
    return true;
}

void Modulo::exibir()
{
    std::cout << tipo;
}

Modulo::~Modulo()
{
}