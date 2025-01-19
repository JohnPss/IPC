#include "Pessoa.hpp"

Pessoa::Pessoa(const std::string &nome, const std::string &cpf)
    : nome(nome), cpf(cpf) {}

std::string Pessoa::getNome() const
{
    return nome;
}

std::string Pessoa::getCpf() const
{
    return cpf;
}

void Pessoa::setNome(const std::string &nome)
{
    this->nome = nome;
}

void Pessoa::setCpf(const std::string &cpf)
{
    this->cpf = cpf;
}