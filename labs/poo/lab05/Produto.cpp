#include "Produto.hpp"
#include <iostream>

Produto::Produto(const std::string &nome, double preco) : nome(nome), preco(preco) {}

std::string Produto::getDetalhes() const
{
    return "Nome: " + nome + ", Preço: " + std::to_string(preco);
}

std::string Produto::getNome() const
{
    return nome;
}

double Produto::getPreco() const
{
    return preco;
}
