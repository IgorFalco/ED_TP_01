#pragma once
#include "./TipoItem.hpp"

class TipoCelula
{
private:
    TipoItem item;
    TipoCelula *prox;
public:
    TipoCelula();

friend class ListaDinamica;
};
