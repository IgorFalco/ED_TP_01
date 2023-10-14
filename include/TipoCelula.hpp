#pragma once
#include "./TipoItem.hpp"

class TipoCelula
{
private:
    char item;
    TipoCelula *prox;

public:
    TipoCelula()
    {
        item = ' ';
        prox = nullptr;
    };

    friend class Pilha;
};
