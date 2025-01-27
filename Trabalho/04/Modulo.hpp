#pragma once

class Modulo
{
private:
    char tipo;

public:
    Modulo(char tipo);
    Modulo();
    char getTipo() const;
    virtual bool podeAcessar();
    void exibir();

    virtual ~Modulo();
};