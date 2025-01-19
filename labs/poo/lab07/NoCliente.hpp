#ifndef NOCLIENTE_HPP
#define NOCLIENTE_HPP
#include <iostream>
#include "Pessoa.hpp"

using namespace std;

class NoCliente
{
private:
    Pessoa p;
    NoCliente *prox;

public:
    NoCliente(const Pessoa &p);
    Pessoa obterPessoa();
    NoCliente *obterProx();
    void setProx(NoCliente *p);
};

#endif