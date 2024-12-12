#include "Funcionario.hpp"

Funcionairo::Funcionairo(string nome, int salario_base) : nome(nome), salario_base(salario_base) {}

string Funcionairo::Descricao()
{
    return "Funcionario: " + nome + " Salario: " + to_string(salario_base);
}

string Funcionairo::getNome() const
{
    return nome;
}

void Funcionairo::setNome(string nome)
{
    this->nome = nome;
}

int Funcionairo::getSalarioBase()
{
    return salario_base;
}

void Funcionairo::setSalarioBase(int salario_base)
{
    this->salario_base = salario_base;
}