#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include "Cliente.hpp"
#include "Eletronico.hpp"
#include "Vestuario.hpp"

void limparBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Cliente *buscarCliente(std::vector<Cliente> &clientes, const std::string &cpf)
{
    for (auto &cliente : clientes)
    {
        if (cliente.getCPF() == cpf)
        {
            return &cliente;
        }
    }
    return nullptr;
}

Produto cadastrarProduto()
{
    int tipo;
    std::string nome;
    double preco;

    std::cout << "\nTipo de produto:" << std::endl;
    std::cout << "1. Eletrônico" << std::endl;
    std::cout << "2. Vestuário" << std::endl;
    std::cout << "Escolha: ";
    std::cin >> tipo;
    limparBuffer();

    std::cout << "Nome do produto: ";
    std::getline(std::cin, nome);
    std::cout << "Preço: R$ ";
    std::cin >> preco;
    limparBuffer();

    if (tipo == 1)
    {
        int garantia;
        std::cout << "Tempo de garantia (anos): ";
        std::cin >> garantia;
        limparBuffer();
        return Eletronico(garantia, nome, preco);
    }
    else
    {
        std::string tamanho, cor;
        std::cout << "Tamanho: ";
        std::getline(std::cin, tamanho);
        std::cout << "Cor: ";
        std::getline(std::cin, cor);
        return Vestuario(nome, preco, tamanho, cor);
    }
}

int main()
{
    std::vector<Cliente> clientes;
    int opcao;

    do
    {
        std::cout << "\n=== MENU PRINCIPAL ===" << std::endl;
        std::cout << "1. Cadastrar Cliente" << std::endl;
        std::cout << "2. Adicionar Produto a um Cliente" << std::endl;
        std::cout << "3. Exibir Detalhes de um Cliente" << std::endl;
        std::cout << "4. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        limparBuffer();

        switch (opcao)
        {
        case 1:
        {
            std::string nome, cpf;
            std::cout << "\n=== CADASTRO DE CLIENTE ===" << std::endl;
            std::cout << "Nome: ";
            std::getline(std::cin, nome);
            std::cout << "CPF: ";
            std::getline(std::cin, cpf);

            if (buscarCliente(clientes, cpf) != nullptr)
            {
                std::cout << "Erro: CPF já cadastrado!" << std::endl;
            }
            else
            {
                clientes.emplace_back(nome, cpf);
                std::cout << "Cliente cadastrado com sucesso!" << std::endl;
            }
            break;
        }
        case 2:
        {
            std::string cpf;
            std::cout << "\n=== ADICIONAR PRODUTO ===" << std::endl;
            std::cout << "CPF do cliente: ";
            std::getline(std::cin, cpf);

            Cliente *cliente = buscarCliente(clientes, cpf);
            if (cliente == nullptr)
            {
                std::cout << "Erro: Cliente não encontrado!" << std::endl;
            }
            else
            {
                char continuar;
                do
                {
                    Produto produto = cadastrarProduto();
                    cliente->adicionaCompra(produto);
                    std::cout << "Produto adicionado com sucesso!" << std::endl;

                    std::cout << "Deseja adicionar outro produto? (S/N): ";
                    std::cin >> continuar;
                    limparBuffer();
                } while (toupper(continuar) == 'S');
            }
            break;
        }
        case 3:
        {
            std::string cpf;
            std::cout << "\n=== DETALHES DO CLIENTE ===" << std::endl;
            std::cout << "CPF do cliente: ";
            std::getline(std::cin, cpf);

            Cliente *cliente = buscarCliente(clientes, cpf);
            if (cliente == nullptr)
            {
                std::cout << "Erro: Cliente não encontrado!" << std::endl;
            }
            else
            {
                std::cout << std::fixed << std::setprecision(2);
                std::cout << cliente->getDetalhes() << std::endl;
            }
            break;
        }
        case 4:
            std::cout << "Encerrando o programa..." << std::endl;
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcao != 4);

    return 0;
}