#include "../include/TipoItem.hpp"

TipoItem::TipoItem()
{
    formula = " ";
    stringDeAnalise = " ";
    satisfaz = false;
    quantificadorDaFormula = ' ';
    posicao = -1;
}

void TipoItem::setFormula(std::string _Formula)
{
    formula = _Formula;
}

void TipoItem::setPosicao(int pos)
{
    posicao = pos;
}

void TipoItem::setSatisfaz(bool resultado)
{
    satisfaz = resultado;
}

void TipoItem::setQuantificadorDaFormula(char quantificador)
{
    quantificadorDaFormula = quantificador;
}
void TipoItem::setString(std::string Analise)
{
    stringDeAnalise = Analise;
}

std::string TipoItem::getFormula()
{
    return formula;
}

std::string TipoItem::getAnalise()
{
    return stringDeAnalise;
}

bool TipoItem::getSatisfaz()
{
    return satisfaz;
}
int TipoItem::getPosicao()
{
    return posicao;
}

char TipoItem::getQuantificadorDaFormula()
{
    return quantificadorDaFormula;
}
