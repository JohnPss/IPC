#pragma once
#include <string>
using namespace std;

class Funcionairo
{
private:
    string nome;
    int salario_base;

public:
    Funcionairo(string nome, int salario_base);
    virtual string Descricao();

    string getNome() const;
    void setNome(string nome);
    int getSalarioBase();
    void setSalarioBase(int salario_base);
};