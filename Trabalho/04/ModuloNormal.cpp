#include "ModuloNormal.hpp"

ModuloNormal::ModuloNormal(char tipo) : Modulo(tipo)
{
}

bool ModuloNormal::podeAcessar()
{
    return true;
}