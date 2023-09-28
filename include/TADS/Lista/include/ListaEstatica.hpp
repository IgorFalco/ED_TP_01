#pragma once

#include "./Lista.hpp"

class ListaEstatica : public Lista
{
private:
    static const int MAXTAM = 100;
    TipoItem itens[MAXTAM];

public:
    ListaEstatica() : Lista() {};
    TipoItem GetItem(int pos);
    void SetItem(TipoItem item, int pos);
    void InsereInicio(TipoItem item);
    void InsereFinal(TipoItem item);
    void InserePosicao(TipoItem item, int pos);
    TipoItem RemoveInicio();
    TipoItem RemoveFinal();
    TipoItem RemovePosicao(int pos);
    TipoItem Pesquisa(TipoChave c);
    void Imprime();
    void Limpa();
};