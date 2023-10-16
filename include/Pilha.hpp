#pragma once
#include "TipoCelula.hpp"

class Pilha
{
public:
    Pilha();
    ~Pilha();

    // Adiciona um novo elemento na pilha
    void push(char c);
    // Revome o topo
    const char pop();
    // Retorna o topo
    const char top();
    // Limpa a Pilha
    void Limpa();
    // Retorna se a pilha esta vazia
    bool empty();

private:
    TipoCelula *topo;
    int tamanho;
};