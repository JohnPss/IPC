#include "NoHistoricoPedido.hpp"

NoPedidoHistorico::NoPedidoHistorico(const Pedido &p, NoPedidoHistorico *prox)
    : pedido(p), prox(prox)
{
}
Pedido NoPedidoHistorico::getPedido()
{
    return pedido;
}

NoPedidoHistorico *NoPedidoHistorico::getProx()
{
    return prox;
}

void NoPedidoHistorico::setProx(NoPedidoHistorico *p)
{
    prox = p;
}