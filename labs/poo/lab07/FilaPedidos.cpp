
#include "FilaPedidos.hpp"

FilaPedidos::FilaPedidos() : cabeca(nullptr), calda(nullptr) {}

FilaPedidos::FilaPedidos(Pedido pedido)
{
    cabeca = new NoPedido(pedido);
    calda = cabeca;
}

FilaPedidos::~FilaPedidos()
{
    delete cabeca;
}

void FilaPedidos::enfilerarPedido(Pedido pedido)
{
    NoPedido *novoPedido = new NoPedido(pedido);

    if (cabeca == nullptr)
    {
        cabeca = novoPedido;
        calda = cabeca;
    }
    else
    {
        calda->setProx(novoPedido);
        calda = novoPedido;
    }
}

Pedido FilaPedidos::FilaPedidos::desenfilerarPedido()
{
    if (cabeca == nullptr)
    {
        throw std::runtime_error("Fila vazia!");
    }

    NoPedido *temp = cabeca;
    Pedido pedido = temp->obterPedido();
    cabeca = cabeca->obterProx();

    if (cabeca == nullptr)
    {
        calda = nullptr;
    }

    delete temp;
    return pedido;
}

void FilaPedidos::exbirPedidos()
{
    NoPedido *aux = cabeca;

    while (aux != nullptr)
    {
        cout << "Código do Pedido: " << aux->obterPedido().getCodigoPedido() << endl;
        cout << "Descrição do Pedido: " << aux->obterPedido().getDescricaoPedido() << endl;
        cout << "Tempo Estimado: " << aux->obterPedido().getTempoEstimado() << endl;
        cout << "CPF do Cliente: " << aux->obterPedido().getCPF() << endl;
        cout << endl;

        aux = aux->obterProx();
    }
}