#include <ModuloObstaculo.hpp>

ModuloObstaculo::ModuloObstaculo(char tipo) : Modulo(tipo)
{
}

bool ModuloObstaculo::podeAcessar()
{
    return false;
}