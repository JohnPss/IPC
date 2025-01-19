#pragma once

#include "NoPedido.hpp"
#include "Pedido.hpp"

class FilaPedidos
{
private:
    NoPedido *cabeca;
    NoPedido *cauda;

public:
    FilaPedidos();
    FilaPedidos(Pedido pedido);
    virtual ~FilaPedidos();
    void enfilerarPedido(Pedido pedido);
    Pedido desenfilerarPedido();
    void exibirPedidos();
};