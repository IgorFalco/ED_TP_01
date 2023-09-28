#pragma once

#include "./TipoItem.hpp"
#include "./TipoCelula.hpp"

class Lista
{
protected:
    int tamanho;

public:
    Lista() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };

    virtual TipoItem GetItem(int pos) = 0;
    virtual void SetItem(TipoItem, int pos) = 0;
    virtual void InsereInicio(TipoItem item) = 0;
    virtual void InsereFinal(TipoItem item) = 0;
    virtual void InserePosicao(TipoItem item, int pos) = 0;
    virtual TipoItem RemoveInicio() = 0;
    virtual TipoItem RemoveFinal() = 0;
    virtual TipoItem RemovePosicao(int pos) = 0;
    virtual void Imprime() = 0;
    virtual void Limpa() = 0;
};