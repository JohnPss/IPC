#include "HistoricoPedidos.hpp"

HistoricoPedidos::HistoricoPedidos(ListaCliente &lista)
    : inicio(nullptr), listaClientes(lista) {}

void HistoricoPedidos::adicionarPedido(const Pedido &pedido)
{
    NoPedidoHistorico *novo = new NoPedidoHistorico(pedido);

    if (inicio == nullptr)
    {
        inicio = novo;
        return;
    }

    novo->setProx(inicio);
    inicio = novo;
}

void HistoricoPedidos::exibirHistorico()
{
    if (inicio == nullptr)
    {
        std::cout << "Histórico de pedidos vazio!" << std::endl;
        return;
    }

    std::cout << "\n====== HISTÓRICO DE PEDIDOS ======" << std::endl;
    NoPedidoHistorico *atual = inicio;
    int numeroPedido = 1;

    while (atual != nullptr)
    {
        Pedido pedido = atual->getPedido();
        Pessoa cliente = listaClientes.buscarClientePorCPF(pedido.getCPF()); // Corrigido aqui

        std::cout << "\nPEDIDO CONCLUÍDO #" << numeroPedido << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "DADOS DO PEDIDO:" << std::endl;
        std::cout << "Código: " << pedido.getCodigoPedido() << std::endl;
        std::cout << "Descrição: " << pedido.getDescricaoPedido() << std::endl;
        std::cout << "Tempo Estimado: " << pedido.getTempoEstimado() << " minutos" << std::endl;

        std::cout << "\nDADOS DO CLIENTE:" << std::endl;
        std::cout << "Nome: " << cliente.getNome() << std::endl;
        std::cout << "CPF: " << cliente.getCpf() << std::endl;

        std::cout << "========================" << std::endl;

        atual = atual->getProx();
        numeroPedido++;
    }
}

HistoricoPedidos::~HistoricoPedidos()
{
    NoPedidoHistorico *atual = inicio;
    while (atual != nullptr)
    {
        NoPedidoHistorico *temp = atual;
        atual = atual->getProx();
        delete temp;
    }
}
