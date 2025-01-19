#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string>

class Pedido
{
private:
    int codigoPedido;
    std::string descricaoPedido;
    int tempoEstimado;
    std::string CPF;

public:
    // Constructor
    Pedido(int codigo, const std::string &descricao, int tempo, const std::string &cpf);

    // Getters
    int getCodigoPedido() const;
    std::string getDescricaoPedido() const;
    int getTempoEstimado() const;
    std::string getCPF() const;

    // Setters
    void setCodigoPedido(int codigo);
    void setDescricaoPedido(const std::string &descricao);
    void setTempoEstimado(int tempo);
    void setCPF(const std::string &cpf);
};

#endif // PEDIDO_HPP