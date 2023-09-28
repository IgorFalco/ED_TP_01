#pragma once


typedef int TipoChave;

class TipoItem
{
private:
    TipoChave chave;

public:
    TipoItem();
    TipoItem(TipoChave c);
    void SetChave(TipoChave c);
    TipoChave GetChave();
    void Imprime();
};
