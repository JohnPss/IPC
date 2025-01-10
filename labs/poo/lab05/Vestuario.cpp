#include "Vestuario.hpp"

Vestuario::Vestuario(std::string nome, double preco, std::string tamanho, std::string cor)
    : Produto(nome, preco), tamanho(tamanho), cor(cor) {}

std::string Vestuario::getDetalhes() const
{
    return "Nome: " + getNome() + ", Preço: " + std::to_string(getPreco()) + ", Tamanho: " + tamanho + ", Cor: " + cor;
}

std::string Vestuario::getTamanho() const
{
    return tamanho;
}

std::string Vestuario::getCor() const
{
    return cor;
}