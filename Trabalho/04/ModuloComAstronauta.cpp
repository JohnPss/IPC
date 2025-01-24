#include "ModuloComAstronauta.hpp"
#include "Astronauta.hpp"
using namespace std;

ModuloComAstronauta::ModuloComAstronauta(char tipo) : Modulo(tipo)
{
}

bool ModuloComAstronauta::podeAcessar()
{
    return true;
}