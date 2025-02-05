#pragma once

#include <string>
class Astronauta
{
private:
    std::string nome;
    int nivelSaude;
    bool atendimentoUrgente;
    int x;
    int y;

public:
    Astronauta(std::string nome, int nivelSaude, bool atendimentoUrgente, int x, int y);

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    std::string getNome();
    int getNivelSaude();
    bool isAtendimentoUrgente();

    std::string toString();
};