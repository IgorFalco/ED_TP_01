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

    TipoItem();
    void setFormula(std::string _Formula);
    void setPosicao(int pos);
    void setSatisfaz(bool resultado);
    void setQuantificadorDaFormula(char quantificador);
    void setString(std::string Analise);
    std::string getFormula();
    std::string getAnalise();
    bool getSatisfaz();
    int getPosicao();
    char getQuantificadorDaFormula();
};
