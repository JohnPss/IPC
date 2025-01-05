#include "Desenvolvedor.hpp"

Desenvolvedor::Desenvolvedor(string linguaguem_principal, string nome, int salario_base)
    : linguaguem_principal(linguaguem_principal), Funcionairo(nome, salario_base) {}

// Desenvolvedor::Desenvolvedor(string linguaguem_principal) : linguaguem_principal(linguaguem_principal) {}

string Desenvolvedor::projetos_realizados()
{
    return "Projetos entregues na linguagem: " + linguaguem_principal;
}

string Desenvolvedor::getLingaguemPrincipal() const
{
    return linguaguem_principal;
}

void Desenvolvedor::setLinguaguemPrincipal(const string &lingaguem_principal)
{
    this->linguaguem_principal = linguaguem_principal;
}

string Desenvolvedor::Descricao()
{
    return "Nome: " + getNome() + "\nSalario: " + to_string(getSalarioBase()) + "\nLinguagem principal: " + getLingaguemPrincipal();
}