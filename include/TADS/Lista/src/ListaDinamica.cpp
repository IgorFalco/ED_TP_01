#include "../include/ListaDinamica.hpp"


ListaDinamica::ListaDinamica() : Lista()
{
    primeiro = new TipoCelula();
    ultimo = primeiro;
};
// O(n)
ListaDinamica::~ListaDinamica()
{
    Limpa();
    delete primeiro;
};
// O(n)
TipoCelula *ListaDinamica::Posiciona(int pos, bool antes = false)
{
    TipoCelula *p;
    int i;

    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";

    p = primeiro;
    for (i = 0; i < pos; i++)
        p = p->prox;

    if (!antes)
        p = p->prox;

    return p;
};
TipoItem ListaDinamica::GetItem(int pos)
{
    TipoCelula *p;
    p = Posiciona(pos);
    return p->item;
};
void ListaDinamica::SetItem(TipoItem item, int pos)
{
    TipoCelula *p;
    p = Posiciona(pos);
    p->item = item;
};
// O(1)
void ListaDinamica::InsereInicio(TipoItem item)
{
    TipoCelula *nova = new TipoCelula();

    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

    if (nova->prox == nullptr)
        ultimo = nova;
};
// O(1)
void ListaDinamica::InsereFinal(TipoItem item)
{
    TipoCelula *nova = new TipoCelula();

    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
};
// O(n)
void ListaDinamica::InserePosicao(TipoItem item, int pos)
{
    TipoCelula *nova = new TipoCelula();
    TipoCelula *p;

    p = Posiciona(pos, true);

    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;

    if (nova->prox == nullptr)
        ultimo = nova;
};
// O(1)
TipoItem ListaDinamica::RemoveInicio()
{
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO:Lista vazia!";
    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;

    if (primeiro->prox == nullptr)
    {
        ultimo = primeiro;
    }
    aux = p->item;
    delete p;

    return aux;
};
// O(n)
TipoItem ListaDinamica::RemoveFinal()
{

    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO:Lista vazia!";

    p = Posiciona(tamanho, true);

    p->prox = nullptr;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;

    return aux;
};
// O(n)
TipoItem ListaDinamica::RemovePosicao(int pos)
{
    TipoItem aux;
    TipoCelula *p, *q;

    if (tamanho == 0)
        throw "ERRO:Lista vazia!";

    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if (p->prox == nullptr)
        ultimo = p;

    return aux;
};
// O(n)
TipoItem ListaDinamica::Pesquisa(TipoChave c)
{
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO:Lista vazia!";

    p = primeiro->prox;

    aux.SetChave(-1);

    while (p != nullptr)
    {
        if (p->item.GetChave() == c)
        {
            aux = p->item;
            break;
        }
        p = p->prox;
    }
    return aux;
};
void ListaDinamica::Imprime()
{
    TipoCelula *p;
    p = primeiro->prox;
    while (p != nullptr)
    {
        p->item.Imprime();
        p = p->prox;
    }
};
// O(n)
void ListaDinamica::Limpa()
{
    TipoCelula *p;

    p = primeiro->prox;

    while (p != nullptr)
    {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
};