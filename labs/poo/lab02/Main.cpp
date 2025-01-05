#include <iostream>
#include <string>
#include "Biblioteca.hpp"
#include "Livro.hpp"
#include "Autor.hpp"

// using namespace std;

int main()
{
    int opcao;
    Biblioteca biblioteca;
    do
    {
        std::cout << "Digite uma das opções abaixo: " << std::endl;
        std::cout << "1 - Adicionar livro" << std::endl;
        std::cout << "2 - Buscar livro" << std::endl;
        std::cout << "3 - Mostrar livros" << std::endl;
        std::cout << "4 - Sair" << std::endl;

        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            std::string titulo, ISBN, nome, dataDeNascimento;
            std::cout << "Digite o titulo do livro: ";
            std::cin >> titulo;
            std::cout << "Digite o ISBN do livro: ";
            std::cin >> ISBN;
            std::cout << "Digite o nome do autor: ";
            std::cin >> nome;
            std::cout << "Digite a data de nascimento do autor: ";
            std::cin >> dataDeNascimento;

            Autor autor(nome, dataDeNascimento);
            Livro livro(titulo, ISBN, autor);
            biblioteca.adicionarLivro(livro);
            break;
        }
        case 2:
        {
            std::string titulo;
            std::string autor;
            std::cout << "Digite o titulo do livro: ";
            std::cin >> titulo;
            std::cout << "Digite o autor: ";
            std::cin >> autor;

            std::vector<Livro> livros = biblioteca.buscarLivro(titulo, autor);

            if (livros.size() == 0)
            {
                std::cout << "Livro não encontrado" << std::endl;
                break;
            }

            for (Livro livro : livros)
            {
                std::cout << "\nTitulo: " << livro.getTitulo() << std::endl;
                std::cout << "ISBN: " << livro.getISBN() << std::endl;
                std::cout << "Autor: " << livro.getAutor().getNome() << std::endl;
                std::cout << "Data de nascimento do autor: " << livro.getAutor().getDataDeNascimento() << std::endl;
                std::cout << std::endl;
            }

            break;
        }
        case 3:
        {
            biblioteca.mostrarLivros();
            break;
        }
        }
    } while (opcao != 4);

    return 0;
}
