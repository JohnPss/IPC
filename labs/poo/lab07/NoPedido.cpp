#include "NoPedido.hpp"

NoPedido::NoPedido(const Pedido &p) : p(p) {}

Pedido NoPedido::obterPedido()
{
    return p;
};

NoPedido *NoPedido::obterProx()
{
    return prox;
}

void NoPedido::setProx(NoPedido *p)
{
    prox = p;
};