#include "../include/ListaEstatica.hpp"
#include <iostream>

// O(1)
TipoItem ListaEstatica::GetItem(int pos)
{
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";

    return itens[pos - 1];
};
// O(1)
void ListaEstatica::SetItem(TipoItem item, int pos)
{
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";

    itens[pos - 1] = item;
};
// O(n)
void ListaEstatica::InsereInicio(TipoItem item)
{
    if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";

    tamanho++;

    for (int i = tamanho; i > 0; i--)
        itens[i] = itens[i - 1];

    itens[0] = item;
};
// O(1)
void ListaEstatica::InsereFinal(TipoItem item)
{
    if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";

    tamanho++;

    itens[tamanho - 1] = item;
};
// O(n)
void ListaEstatica::InserePosicao(TipoItem item, int pos)
{
    if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";

    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";

    tamanho++;
    pos--;

    for (int i = tamanho; i > pos; i--)
        itens[i] = itens[i - 1];

    itens[pos] = item;
};
// O(1)
TipoItem ListaEstatica::RemoveFinal()
{
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    tamanho--;
    TipoItem aux = itens[tamanho];

    return aux;
};
// O(n)
TipoItem ListaEstatica::RemoveInicio()
{
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    TipoItem aux = itens[0];

    for (int i = 0; i < tamanho; i++)
        itens[i] = itens[i + 1];

    tamanho--;

    return aux;
};
// O(n)
TipoItem ListaEstatica::RemovePosicao(int pos)
{

    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";

    pos--;

    TipoItem aux = itens[pos];
    for (int i = pos; i < tamanho; i++)
        itens[i] = itens[i + 1];
    tamanho--;

    return aux;
};
// O(n)
TipoItem ListaEstatica::Pesquisa(TipoChave c)
{
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    TipoItem aux;

    aux.SetChave(-1);
    for (int i = 0; i < tamanho; i++)
    {
        if (itens[i].GetChave() == c)
        {
            aux = itens[i];
            break;
        }
    }
    return aux;
};
// O(n)
void ListaEstatica::Imprime()
{
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    for (int i = 0; i < tamanho; i++)
    {
        itens[i].Imprime();
    }
};

// O(1)
void ListaEstatica::Limpa()
{
    tamanho = 0;
};