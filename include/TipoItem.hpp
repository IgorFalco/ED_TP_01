#pragma once
#include <iostream>

class TipoItem
{
private:
    std::string formula;
    std::string stringDeAnalise;
    int posicao;
    bool satisfaz;
    char quantificadorDaFormula;

public:
    TipoItem()
    {
        formula = " ";
        stringDeAnalise = " ";
        satisfaz = false;
        quantificadorDaFormula = ' ';
        posicao = -1;
    }

    void setFormula(std::string _Formula)
    {
        formula = _Formula;
    }

    void setPosicao(int pos)
    {
        posicao = pos;
    }

    void setSatisfaz(bool resultado)
    {
        satisfaz = resultado;
    }

    void setQuantificadorDaFormula(char quantificador)
    {
        quantificadorDaFormula = quantificador;
    }
    void setString(std::string Analise)
    {
        stringDeAnalise = Analise;
    }

    std::string getFormula()
    {
        return formula;
    }

    std::string getAnalise()
    {
        return stringDeAnalise;
    }

    bool getSatisfaz()
    {
        return satisfaz;
    }
    int getPosicao()
    {
        return posicao;
    }

    char getQuantificadorDaFormula()
    {
        return quantificadorDaFormula;
    }
};
