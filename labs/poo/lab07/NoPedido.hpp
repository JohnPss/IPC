#pragma once
#include <iostream>
#include "Pedido.hpp"

using namespace std;

class NoPedido
{
private:
    Pedido p;
    NoPedido *prox;

public:
    NoPedido(const Pedido &p);
    Pedido obterPedido();
    NoPedido *obterProx();
    void setProx(NoPedido *p);
};
