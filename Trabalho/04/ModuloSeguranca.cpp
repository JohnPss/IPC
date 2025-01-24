#include "ModuloSeguranca.hpp"

ModuloSeguranca::ModuloSeguranca(char tipo) : Modulo(tipo)
{
}

bool ModuloSeguranca::podeAcessar()
{
    return true;
}