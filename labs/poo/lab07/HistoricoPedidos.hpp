#pragma once
#include <iostream>
#include "NoHistoricoPedido.hpp"
#include "ListaCliente.hpp"

class HistoricoPedidos
{
private:
    NoPedidoHistorico *inicio;
    ListaCliente &listaClientes;

public:
    HistoricoPedidos(ListaCliente &lista);

    void adicionarPedido(const Pedido &pedido);

    void exibirHistorico();

    ~HistoricoPedidos();
};