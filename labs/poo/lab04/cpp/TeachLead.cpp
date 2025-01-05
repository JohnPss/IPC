#include "TeachLead.hpp"

TeachLead::TeachLead(string nome, int salario_base, int numero_equipes, string linguagem_principal)
    : Funcionairo(nome, salario_base), Desenvolvedor(linguagem_principal, nome, salario_base), Gerente(numero_equipes, nome, salario_base) {}

int TeachLead::getProjetosEmAndamento()
{
    return this->projetos_em_andamento;
}

string TeachLead::Descricao()
{
    return "Nome: " + getNome() + "\nSalario: " + to_string(getSalarioBase()) + "\nNumero de equipes: " + to_string(getNumeroEquipes()) + "\nLinguagem principal: " + getLingaguemPrincipal() + "\nProjetos em andamento: " + to_string(getProjetosEmAndamento()) + "\nBonus: " + to_string(bonus());
}