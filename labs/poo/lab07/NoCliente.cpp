#include "NoCliente.hpp"

NoCliente::NoCliente(const Pessoa &p)
    : p(p) {}

Pessoa NoCliente::obterPessoa()
{
    return p;
}

NoCliente *NoCliente::obterProx()
{
    return prox;
}

void NoCliente::setProx(NoCliente *p)
{
    prox = p;
}