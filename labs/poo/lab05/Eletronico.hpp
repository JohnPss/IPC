#ifndef ELETRONICO_HPP
#define ELETRONICO_HPP

#include "Produto.hpp"
#include <string>

class Eletronico : public Produto
{
private:
    int garantia;

public:
    Eletronico(int garantia, const std::string &nome, double preco);

    std::string getDetalhes() const override;
};

#endif // ELETRONICO_HPP