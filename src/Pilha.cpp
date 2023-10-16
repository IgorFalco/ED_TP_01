#include "../include/Pilha.hpp"

Pilha::Pilha()
{
    topo = nullptr;
    tamanho = 0;
}

Pilha::~Pilha()
{
    Limpa();
}

void Pilha::push(char c)
{
    TipoCelula *nova;

    nova = new TipoCelula;
    nova->item = c;
    nova->prox = topo;
    topo = nova;
    tamanho++;
}

const char Pilha::pop()
{
    TipoCelula *p;
    char aux;

    if (tamanho == 0)
        throw "A pilha está vazia";

    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;

    return aux;
}

const char Pilha::top()
{
    return topo->item;
}

void Pilha::Limpa()
{
    while (!empty())
        pop();
}

bool Pilha::empty()
{
    if (tamanho == 0)
        return true;
    else
        return false;
}