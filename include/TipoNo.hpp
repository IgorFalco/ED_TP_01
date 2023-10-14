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
        item.setExpressao("");
        item.setQuantificadorDaExpressao(' ');
        item.setSatisfaz(false);
        esq = nullptr;
        dir = nullptr;
    };

    friend class Arvore;
};
