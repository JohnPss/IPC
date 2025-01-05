#include "Autor.hpp"

Autor::Autor(std::string nome, std::string dataDeNascimento)
    : nome(nome), dataDeNascimento(dataDeNascimento) {}

std::string Autor::getNome()
{
    return nome;
}

void Autor::setNome(std::string nome)
{
    this->nome = nome;
}

std::string Autor::getDataDeNascimento()
{
    return dataDeNascimento;
}

void Autor::setDataDeNascimento(std::string dataDeNascimento)
{
    this->dataDeNascimento = dataDeNascimento;
}