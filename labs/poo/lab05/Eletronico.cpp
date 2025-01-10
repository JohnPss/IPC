#include "Eletronico.hpp"

Eletronico::Eletronico(int garantia, const std::string &nome, double preco)
    : Produto(nome, preco), garantia(garantia) {}

std::string Eletronico::getDetalhes() const
{
    return "Nome: " + getNome() + ", Preço: " + std::to_string(getPreco()) + ", Garantia: " + std::to_string(garantia) + " anos";
}