#pragma once
#include <string>
#include <vector>
#include "Livro.hpp"
class Biblioteca
{
private:
    std::vector<Livro> livros;

public:
    Biblioteca();
    void adicionarLivro(Livro livro);
    std::vector<Livro> buscarLivro(std::string titulo, std::string autor);
    void mostrarLivros();
};