#include "Astronauta.hpp"

Astronauta::Astronauta(std::string nome, int nivelSaude, bool atendimentoUrgente, int x, int y)
{
    this->nome = nome;
    this->nivelSaude = nivelSaude;
    this->atendimentoUrgente = atendimentoUrgente;
    this->x = x;
    this->y = y;
}

int Astronauta::getX()
{
    return x;
}

int Astronauta::getY()
{
    return y;
}

void Astronauta::setX(int x)
{
    this->x = x;
}

void Astronauta::setY(int y)
{
    this->y = y;
}

std::string Astronauta::getNome()
{
    return nome;
}

int Astronauta::getNivelSaude()
{
    return nivelSaude;
}

bool Astronauta::isAtendimentoUrgente()
{
    return atendimentoUrgente;
}

std::string Astronauta::toString()
{
    return "Nome: " + nome + ", Nivel Saude: " + std::to_string(nivelSaude) + ", Urgencia: " + std::to_string(atendimentoUrgente) + ", Posicao: (" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
