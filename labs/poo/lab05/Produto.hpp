#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto
{
private:
    std::string nome;
    double preco;

public:
    Produto(const std::string &nome, double preco);

    virtual std::string getDetalhes() const;
    std::string getNome() const;
    double getPreco() const;
};

#endif // PRODUTO_HPP