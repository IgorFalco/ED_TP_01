#pragma once
#include "../include/TipoNo.hpp"

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void Insere(TipoItem Item);
    void Caminha(int tipo);
    void Limpa();

private:
    void InsereRecursivo(TipoNo *&p, TipoItem Item);
    void ApagaRecursivo(TipoNo *p);
    void PorNivel();
    void PreNivel();
    void InOrdem();
    void PosOrdem();

    TipoNo *raiz;
};