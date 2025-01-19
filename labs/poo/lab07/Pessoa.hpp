#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa
{
private:
    std::string nome;
    std::string cpf;

public:
    Pessoa(const std::string &nome, const std::string &cpf);

    std::string getNome() const;

    std::string getCpf() const;

    void setNome(const std::string &nome);

    void setCpf(const std::string &cpf);
};

#endif // PESSOA_HPP