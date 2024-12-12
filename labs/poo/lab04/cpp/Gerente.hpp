#pragma once
#include "Funcionario.hpp"

class Gerente : virtual public Funcionairo
{
private:
    int numero_equipes;

public:
    Gerente(int numero_equipes, string nome, int salario_base);
    int bonus();
    int getNumeroEquipes() const;
    void setNumeroEquipes(int numero_equipes);
    string Descricao() override;
};
