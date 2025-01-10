#ifndef VESTUARIO_HPP
#define VESTUARIO_HPP

#include <string>
#include "Produto.hpp"

class Vestuario : public Produto
{
private:
    std::string tamanho;
    std::string cor;

public:
    Vestuario(std::string nome, double preco, std::string tamanho, std::string cor);

    std::string getDetalhes() const override;

    std::string getTamanho() const;
    std::string getCor() const;
};

#endif // VESTUARIO_HPP