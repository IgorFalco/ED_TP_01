#pragma once
#include "TipoNo.hpp"
class Arvore
{
public:
    Arvore();
    ~Arvore();

    void Insere(TipoItem Item);
    void Caminha(TipoNo *p);
    void Caminha(int tipo);
    void Limpa();
    TipoNo *getRaiz();

private:
    void InsereRecursivo(TipoNo *&p, TipoItem Item);
    void ApagaRecursivo(TipoNo *p);

    TipoNo *raiz;
};