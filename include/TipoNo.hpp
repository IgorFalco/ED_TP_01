#pragma once
#include "./TipoItem.hpp"

class TipoNo
{
private:
    TipoItem item;
    TipoNo *esq;
    TipoNo *dir;

public:
    TipoNo()
    {
        item.SetChave("");
        esq = nullptr;
        dir = nullptr;
    };

    friend class ArvoreBinaria;
};
