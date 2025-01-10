#include "Cliente.hpp"

Cliente::Cliente(const std::string &nome, const std::string &CPF) : nome(nome), CPF(CPF) {}

void Cliente::adicionaCompra(const Produto &p)
{
    compras.push_back(p);
}

double Cliente::calculaTotal() const
{
    double total = 0.0;
    for (const auto &produto : compras)
    {
        total += produto.getPreco();
    }
    return total;
}

std::string Cliente::getDetalhes() const
{
    std::string detalhes = "Nome: " + nome + "\nCPF: " + CPF + "\nCompras:\n";
    for (const auto &produto : compras)
    {
        detalhes += produto.getNome() + " - " + std::to_string(produto.getPreco()) + "\n";
    }
    detalhes += "Total: " + std::to_string(calculaTotal()) + "\n";
    return detalhes;
}

std::string Cliente::getNome() const
{
    return nome;
}

std::string Cliente::getCPF() const
{
    return CPF;
}

std::vector<Produto> Cliente::getCompras() const
{
    return compras;
}