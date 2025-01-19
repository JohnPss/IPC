#include <iostream>
#include "Pedido.hpp"
#include "Pessoa.hpp"
#include "NoCliente.hpp"
#include "ListaCliente.hpp"
#include "FilaPedidos.hpp"
#include "HistoricoPedidos.hpp"

using namespace std;

void exibirMenu()
{
    cout << "\n====== MENU DO RESTAURANTE ======" << endl;
    cout << "1. Adicionar novo cliente" << endl;
    cout << "2. Adicionar novo pedido" << endl;
    cout << "3. Preparar próximo pedido" << endl;
    cout << "4. Exibir pedidos em espera" << endl;
    cout << "5. Exibir histórico de pedidos" << endl;
    cout << "6. Exibir lista de clientes" << endl;
    cout << "7. Sair" << endl;
    cout << "==============================" << endl;
    cout << "Escolha uma opção: ";
}

int main()
{
    ListaCliente listaClientes;
    FilaPedidos filaPedidos;
    HistoricoPedidos historicoPedidos(listaClientes);
    int opcao;
    int codigoPedido = 1;

    do
    {
        exibirMenu();
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
        {
            string nome, cpf;
            cout << "\nDigite o nome do cliente: ";
            getline(cin, nome);
            cout << "Digite o CPF do cliente: ";
            getline(cin, cpf);

            Pessoa novoCliente(nome, cpf);
            listaClientes.adicionarCliente(novoCliente);
            cout << "Cliente cadastrado com sucesso!" << endl;
            break;
        }

        case 2:
        {
            string cpf, descricao;
            int tempo;

            cout << "\nDigite o CPF do cliente: ";
            getline(cin, cpf);

            Pessoa cliente = listaClientes.buscarClientePorCPF(cpf);
            if (cliente.getCpf() == "")
            {
                cout << "Cliente não encontrado!" << endl;
                break;
            }

            cout << "Digite a descrição do pedido: ";
            getline(cin, descricao);
            cout << "Digite o tempo estimado (em minutos): ";
            cin >> tempo;
            cin.ignore();

            Pedido novoPedido(codigoPedido++, descricao, tempo, cpf);
            filaPedidos.enfilerarPedido(novoPedido);
            cout << "Pedido adicionado com sucesso!" << endl;
            break;
        }

        case 3:
        {
            try
            {
                Pedido pedidoConcluido = filaPedidos.desenfilerarPedido();
                historicoPedidos.adicionarPedido(pedidoConcluido);
                cout << "Pedido #" << pedidoConcluido.getCodigoPedido() << " preparado e movido para o histórico!" << endl;
            }
            catch (const runtime_error &e)
            {
                cout << e.what() << endl;
            }
            break;
        }

        case 4:
        {
            cout << "\nPedidos em espera:" << endl;
            filaPedidos.exibirPedidos();
            break;
        }

        case 5:
        {
            cout << "\nHistórico de pedidos:" << endl;
            historicoPedidos.exibirHistorico();
            break;
        }

        case 6:
        {
            cout << "\nLista de clientes:" << endl;
            listaClientes.exibirClientes();
            break;
        }

        case 7:
        {
            cout << "Encerrando o programa..." << endl;
            break;
        }

        default:
        {
            cout << "Opção inválida! Tente novamente." << endl;
            break;
        }
        }
    } while (opcao != 7);

    return 0;
}