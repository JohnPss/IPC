#pragma once

class Modulo
{
private:
    char tipo;

public:
    Modulo(char tipo);
    Modulo();
    char getTipo();
    virtual bool podeAcessar();
};