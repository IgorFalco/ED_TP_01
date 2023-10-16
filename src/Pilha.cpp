#include "../include/Pilha.hpp"
#include "../include/memlog.hpp"

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
    // defineFaseMemLog(0);
    TipoCelula *nova;

    nova = new TipoCelula;
    nova->item = c;
    nova->prox = topo;
    topo = nova;

    // ESCREVEMEMLOG((long int) (&(nova->item)), sizeof(double), 0);
    // ESCREVEMEMLOG((long int) (&(nova->prox)), sizeof(double), 0);
    tamanho++;
}

const char Pilha::pop()
{
    // defineFaseMemLog(1);
    TipoCelula *p;
    char aux;

    if (tamanho == 0)
        throw "A pilha está vazia";

    aux = topo->item;
    
    // LEMEMLOG((long int) (&(topo->item)), sizeof(double), 0);
    p = topo;
    topo = topo->prox;
    // ESCREVEMEMLOG((long int) (&(topo)), sizeof(double), 0);
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