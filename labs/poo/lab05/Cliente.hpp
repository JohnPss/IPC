#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>
#include "Produto.hpp"

class Cliente
{
private:
    std::string nome;
    std::string CPF;
    std::vector<Produto> compras;

public:
    Cliente(const std::string &nome, const std::string &CPF);

    void adicionaCompra(const Produto &p);
    double calculaTotal() const;
    std::string getDetalhes() const;

    std::string getNome() const;
    std::string getCPF() const;
    std::vector<Produto> getCompras() const;
};

#endif // CLIENTE_HPP