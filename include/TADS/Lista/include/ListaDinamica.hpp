#pragma once
#include "./Lista.hpp"

class ListaDinamica : public Lista
{
private:
    TipoCelula *primeiro;
    TipoCelula *ultimo;
    TipoCelula *Posiciona(int pos, bool antes);

public:
    ListaDinamica();
    ~ListaDinamica();
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