#pragma once
#include <iostream>

class TipoItem
{
private:
    std::string expressao;
    bool satisfaz;
    char quantificadorDaExpressao;

public:
    TipoItem()
    {
        expressao = " ";
        satisfaz = false;
        quantificadorDaExpressao = ' ';
    }

    void setExpressao(std::string _expressao)
    {
        expressao = _expressao;
    }

    void setSatisfaz(bool resultado)
    {
        satisfaz = resultado;
    }

    void setQuantificadorDaExpressao(char quantificador)
    {
        quantificadorDaExpressao = quantificador;
    }

    std::string getExpressao()
    {
        return expressao;
    }

    bool getSatisfaz()
    {
        return satisfaz;
    }

    char getQuantificadorDaExpressao()
    {
        return quantificadorDaExpressao;
    }
};
