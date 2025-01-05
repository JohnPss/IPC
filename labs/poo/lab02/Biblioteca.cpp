#include "Biblioteca.hpp"
#include <iostream>

Biblioteca::Biblioteca() {}

void Biblioteca::adicionarLivro(Livro livro)
{
    livros.push_back(livro);
}

std::vector<Livro> Biblioteca::buscarLivro(std::string titulo, std::string autor)
{
    std::vector<Livro> livrosEncontrados;

    for (Livro livro : livros)
    {
        if (livro.getTitulo() == titulo && livro.getAutor().getNome() == autor)
        {
            livrosEncontrados.push_back(livro);
        }
    }

    return livrosEncontrados;
}

void Biblioteca::mostrarLivros()
{
    for (Livro livro : livros)
    {
        std::cout << "Titulo: " << livro.getTitulo() << std::endl;
        std::cout << "ISBN: " << livro.getISBN() << std::endl;
        std::cout << "Autor: " << livro.getAutor().getNome() << std::endl;
        std::cout << "Data de nascimento do autor: " << livro.getAutor().getDataDeNascimento() << std::endl;
        std::cout << std::endl;
    }
}
