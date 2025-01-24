#include "ModuloComFogo.hpp"

ModuloComFogo::ModuloComFogo(char tipo) : Modulo(tipo)
{
}

bool ModuloComFogo::podeAcessar()
{
    return false;
}