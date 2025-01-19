#include "Pedido.hpp"

Pedido::Pedido(int codigo, const std::string &descricao, int tempo, const std::string &cpf)
    : codigoPedido(codigo), descricaoPedido(descricao), tempoEstimado(tempo), CPF(cpf) {}

// Getters
int Pedido::getCodigoPedido() const { return codigoPedido; }
std::string Pedido::getDescricaoPedido() const { return descricaoPedido; }
int Pedido::getTempoEstimado() const { return tempoEstimado; }
std::string Pedido::getCPF() const { return CPF; }

// Setters
void Pedido::setCodigoPedido(int codigo) { codigoPedido = codigo; }
void Pedido::setDescricaoPedido(const std::string &descricao) { descricaoPedido = descricao; }
void Pedido::setTempoEstimado(int tempo) { tempoEstimado = tempo; }
void Pedido::setCPF(const std::string &cpf) { CPF = cpf; }