#ifndef AUTOR_H
#define AUTOR_H
#include <string>

class Autor
{
private:
    std::string nome;
    std::string dataDeNascimento;

public:
    Autor(std::string nome, std::string dataDeNascimento);

    std::string getNome();

    void setNome(std::string nome);

    std::string getDataDeNascimento();

    void setDataDeNascimento(const std::string dataDeNascimento);
};
#endif // AUTOR_H