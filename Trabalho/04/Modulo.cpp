#include "Modulo.hpp"

Modulo::Modulo()
{
}

Modulo::Modulo(char tipo)
{
    this->tipo = tipo;
}

char Modulo::getTipo()
{
    return tipo;
}
