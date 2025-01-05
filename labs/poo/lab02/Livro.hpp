#pragma once
#include <string>
#include <vector>
#include "Autor.hpp"

class Livro
{
private:
    std::string titulo;
    std::string ISBN;
    Autor autor;

public:
    Livro(std::string titulo, std::string ISBN, Autor autor);

    std::string getTitulo();

    std::string getISBN();

    Autor getAutor();

    void setTitulo(std::string titulo);

    void setISBN(std::string ISBN);

    void setAutor(Autor autor);
};
