#include "ListaCliente.hpp"
#include <iostream>

ListaCliente::ListaCliente() : cabeca(nullptr), cauda(nullptr) {}

ListaCliente::~ListaCliente()
{
    delete cabeca;
}

ListaCliente::ListaCliente(Pessoa cliente)
{
    NoCliente *novo = new NoCliente(cliente);
    cabeca = novo;
    cauda = novo;
}

void ListaCliente::adicionarCliente(Pessoa cliente)
{
    NoCliente *novo = new NoCliente(cliente);

    if (cabeca == nullptr)
    {
        cabeca = novo;
        cauda = novo;
    }
    else
    {
        cauda->setProx(novo);
        cauda = novo;
    }
}

Pessoa ListaCliente::buscarClientePorCPF(std::string CPF)
{
    NoCliente *aux = cabeca;
    while (aux != nullptr)
    {
        if (aux->obterPessoa().getCpf() == CPF)
        {
            return aux->obterPessoa();
        }
        aux = aux->obterProx();
    }
    return Pessoa("", "");
}

void ListaCliente::exibirClientes()
{
    NoCliente *aux = cabeca;
    while (aux != nullptr)
    {
        std::cout << "Nome: " << aux->obterPessoa().getNome() << std::endl;
        std::cout << "CPF: " << aux->obterPessoa().getCpf() << std::endl;
        std::cout << "-----------------" << std::endl;
        aux = aux->obterProx();
    }
}
