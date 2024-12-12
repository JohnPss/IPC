#include <iostream>
#include <vector>
#include <string>
#include "Gerente.hpp"
#include "Desenvolvedor.hpp"
#include "TeachLead.hpp"

int main()
{
    std::vector<Gerente> gerentes;
    std::vector<Desenvolvedor> desenvolvedores;
    std::vector<TeachLead> techLeads;

    int opcao;
    while (true)
    {
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Adicionar Gerente\n";
        std::cout << "2. Adicionar Desenvolvedor\n";
        std::cout << "3. Adicionar TechLead\n";
        std::cout << "4. Listar todos\n";
        std::cout << "5. Sair\n";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao)
        {
        case 1:
        {
            std::string nomeG;
            int salarioBG, numEG;
            std::cout << "Nome: ";
            std::getline(std::cin, nomeG);
            std::cout << "Salario base: ";
            std::cin >> salarioBG;
            std::cout << "Numero de equipes: ";
            std::cin >> numEG;
            std::cin.ignore();
            gerentes.emplace_back(numEG, nomeG, salarioBG);
            break;
        }
        case 2:
        {
            std::string nomeD, linguagem;
            int salarioBD;
            std::cout << "Nome: ";
            std::getline(std::cin, nomeD);
            std::cout << "Salario base: ";
            std::cin >> salarioBD;
            std::cin.ignore();
            std::cout << "Linguagem: ";
            std::getline(std::cin, linguagem);
            desenvolvedores.emplace_back(linguagem, nomeD, salarioBD);
            break;
        }
        case 3:
        {
            std::string nomeTL, linguagemTL;
            int salarioBTC, numETL;
            std::cout << "Nome: ";
            std::getline(std::cin, nomeTL);
            std::cout << "Salario base: ";
            std::cin >> salarioBTC;
            std::cout << "Numero de equipes: ";
            std::cin >> numETL;
            std::cin.ignore();
            std::cout << "Linguagem: ";
            std::getline(std::cin, linguagemTL);
            techLeads.emplace_back(nomeTL, salarioBTC, numETL, linguagemTL);
            break;
        }
        case 4:
        {

            cout << '------------------------' << endl;

            if (!gerentes.empty())
            {
                std::cout << "Gerentes:\n";
                for (const auto &gerente : gerentes)
                {
                    std::cout << gerente.getNome() << "\n";
                }
            }
            else
            {
                std::cout << "Nenhum gerente cadastrado.\n";
            }

            cout << '------------------------' << endl;

            if (!desenvolvedores.empty())
            {
                std::cout << "Desenvolvedores:\n";
                for (const auto &desenvolvedor : desenvolvedores)
                {
                    std::cout << desenvolvedor.getNome() << "\n";
                }
            }
            else
            {
                std::cout << "Nenhum desenvolvedor cadastrado.\n";
            }

            cout << '------------------------' << endl;

            if (!techLeads.empty())
            {
                std::cout << "TechLeads:\n";
                for (const auto &techLead : techLeads)
                {
                    std::cout << techLead.getNome() << "\n";
                }
            }
            else
            {
                std::cout << "Nenhum TechLead cadastrado.\n";
            }

            cout << '------------------------' << endl;

            break;
        }
        case 5:
            return 0;
        default:
            std::cout << "Opção inválida.\n";
            break;
        }
    }
}