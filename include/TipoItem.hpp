#pragma once
#include <iostream>

class TipoItem
{
private:
    std::string formula;

    //String binaria
    std::string stringDeAnalise;
    //Posicao em que existia uma variável quantificada naquele nó, antes de trocar essa variável por um '0' ou '1'
    int posicao;
    //Se o nó satisfaz a fórmula
    bool satisfaz;
    //Quantificador que diz qual operação fazer com os filhos
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
