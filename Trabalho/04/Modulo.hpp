#pragma once

class Modulo
{
private:
    char tipo;

public:
    Modulo(char tipo);
    char getTipo();
    virtual bool podeAcessar();
};