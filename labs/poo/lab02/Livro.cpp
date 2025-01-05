#include "Livro.hpp"

Livro::Livro(std::string titulo, std::string ISBN, Autor autor) : titulo(titulo), ISBN(ISBN), autor(autor)
{
}
std::string Livro::getTitulo()
{
    return titulo;
}

std::string Livro::getISBN()
{
    return ISBN;
}

Autor Livro::getAutor()
{
    return autor;
}

void Livro::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

void Livro::setISBN(std::string ISBN)
{
    this->ISBN = ISBN;
}

void Livro::setAutor(Autor autor)
{
    this->autor = autor;
}