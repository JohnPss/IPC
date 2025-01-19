#pragma once
#include "NoCliente.hpp"

class ListaCliente
{
private:
    NoCliente *cabeca;
    NoCliente *cauda;

public:
    ListaCliente();
    ListaCliente(Pessoa cliente);
    virtual ~ListaCliente();
    void adicionarCliente(Pessoa cliente);
    Pessoa buscarClientePorCPF(std::string CPF);
    void exibirClientes();
};