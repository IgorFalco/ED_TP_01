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
        item.setFormula(" ");
        item.setString(" ");
        item.setQuantificadorDaFormula(' ');
        item.setSatisfaz(false);
        esq = nullptr;
        dir = nullptr;
    };

    TipoItem getItem(){
        return item;
    }

    friend class Arvore;
};
