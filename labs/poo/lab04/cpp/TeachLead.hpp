#pragma once
#include "Desenvolvedor.hpp"
#include "Gerente.hpp"

class TeachLead : public Gerente, public Desenvolvedor
{
private:
    int projetos_em_andamento;

public:
    TeachLead(string nome, int salario_base, int numero_equipes, string linguagem_principal);
    virtual ~TeachLead() = default;
    string Descricao() override;
    int getProjetosEmAndamento();
};