#include "ModuloVazio.hpp"

ModuloVazio::ModuloVazio(char tipo) : Modulo(tipo)
{
}

bool ModuloVazio::podeAcessar()
{
    return false;
}