#pragma once
#include "TipoNo.hpp"
class Arvore
{
public:
    Arvore();
    ~Arvore();

    //Insere a formula e a string binária, chama o método InsereRecursivo
    void Insere(TipoItem Item);
    // Caminha por toda a árvore avaliando se cada nó satisfaz o problema. 
    // Caminha de forma PosOrdem
    void Caminha(TipoNo *p);
    void Limpa();
    TipoNo *getRaiz();

private:
    /*
        Insere gerando uma árvore sempre balanceada. A cada novo quantificador é gerado um novo nível na árvore,
        onde o nível abaixo pega esse quantificador e substituí por um número, '0' ou '1';
    */
    void InsereRecursivo(TipoNo *&p, TipoItem Item);
    void ApagaRecursivo(TipoNo *p);

    TipoNo *raiz;
};