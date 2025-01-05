#pragma once
#include "Funcionario.hpp"
class Desenvolvedor : virtual public Funcionairo
{
private:
    string linguaguem_principal;

public:
    Desenvolvedor(string lingaguem_principal, string nome, int salario_base);
    // Desenvolvedor(string lingaguem_principal);
    string projetos_realizados();

    string getLingaguemPrincipal() const;
    void setLinguaguemPrincipal(const string &lingaguem_principal);
    string Descricao() override;
};