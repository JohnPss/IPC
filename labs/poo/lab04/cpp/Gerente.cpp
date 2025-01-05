#include "Gerente.hpp"

Gerente::Gerente(int numero_equipes, string nome, int salario_base) : numero_equipes(numero_equipes), Funcionairo(nome, salario_base) {};

int Gerente::bonus()
{
    return numero_equipes * 500;
}

int Gerente::getNumeroEquipes() const
{
    return numero_equipes;
}

void Gerente::setNumeroEquipes(int numero_equipes)
{
    this->numero_equipes = numero_equipes;
}

string Gerente::Descricao()
{
    return "Nome: " + getNome() + "\nSalario: " + to_string(getSalarioBase()) + "\nNumero de equipes: " + to_string(getNumeroEquipes()) + "\nBonus: " + to_string(bonus());
}