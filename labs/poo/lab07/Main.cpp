#include <iostream>
#include "Pedido.hpp"
#include "Pessoa.hpp"
#include "NoCliente.hpp"
#include "ListaCliente.hpp"
#include "FilaPedidos.hpp"
#include "HistoricoPedidos.hpp"

using namespace std;

int main()
{
    // Criando a lista de clientes e as filas
    ListaCliente listaClientes;
    FilaPedidos filaPedidos;
    HistoricoPedidos historicoPedidos(listaClientes);

    // Cadastrando alguns clientes
    Pessoa p1("João Silva", "123.456.789-00");
    Pessoa p2("Maria Santos", "987.654.321-00");
    Pessoa p3("José Oliveira", "456.789.123-00");

    cout << "\nAdicionando clientes à lista..." << endl;
    listaClientes.adicionarCliente(p1);
    listaClientes.adicionarCliente(p2);
    listaClientes.adicionarCliente(p3);

    cout << "\nExibindo clientes cadastrados:" << endl;
    listaClientes.exibirClientes();

    // Criando alguns pedidos
    cout << "\nCriando pedidos..." << endl;
    Pedido ped1(1, "Pizza Margherita", 30, "123.456.789-00");
    Pedido ped2(2, "Pizza Calabresa", 25, "987.654.321-00");
    Pedido ped3(3, "Pizza Portuguesa", 28, "456.789.123-00");

    // Adicionando pedidos à fila
    cout << "\nAdicionando pedidos à fila..." << endl;
    filaPedidos.enfilerarPedido(ped1);
    filaPedidos.enfilerarPedido(ped2);
    filaPedidos.enfilerarPedido(ped3);

    // Exibindo pedidos em espera
    cout << "\nExibindo pedidos em espera:" << endl;
    filaPedidos.exbirPedidos();

    // Preparando alguns pedidos (movendo para o histórico)
    cout << "\nPreparando pedidos..." << endl;
    try
    {
        Pedido pedidoConcluido = filaPedidos.desenfilerarPedido();
        cout << "Pedido #" << pedidoConcluido.getCodigoPedido() << " concluído!" << endl;
        historicoPedidos.adicionarPedido(pedidoConcluido);

        pedidoConcluido = filaPedidos.desenfilerarPedido();
        cout << "Pedido #" << pedidoConcluido.getCodigoPedido() << " concluído!" << endl;
        historicoPedidos.adicionarPedido(pedidoConcluido);
    }
    catch (const runtime_error &e)
    {
        cout << "Erro: " << e.what() << endl;
    }

    // Exibindo estado atual da fila
    cout << "\nExibindo pedidos ainda em espera:" << endl;
    filaPedidos.exbirPedidos();

    // Exibindo histórico de pedidos
    cout << "\nExibindo histórico de pedidos concluídos:" << endl;
    historicoPedidos.exibirHistorico();

    return 0;
}