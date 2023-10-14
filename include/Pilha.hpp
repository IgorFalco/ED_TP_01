#include "TipoCelula.hpp"

class Pilha
{
public:
    Pilha();
    ~Pilha();

    void push(char c);
    const char pop();
    const char top();
    void Limpa();
    bool empty();

private:
    TipoCelula *topo;
    int tamanho;
};

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
    while (tamanho > 0)
        pop();
}

bool Pilha::empty()
{
    if (tamanho == 0)
        return true;
    else
        return false;
}