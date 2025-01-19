
#ifndef NO_HISTORICO_PEDIDO_HPP
#define NO_HISTORICO_PEDIDO_HPP

#include "Pedido.hpp"

class NoPedidoHistorico
{
private:
    Pedido pedido;
    NoPedidoHistorico *prox;

public:
    NoPedidoHistorico(const Pedido &p, NoPedidoHistorico *prox = nullptr);
    Pedido getPedido();
    NoPedidoHistorico *getProx();
    void setProx(NoPedidoHistorico *p);
};

#endif