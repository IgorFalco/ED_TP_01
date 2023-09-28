#include "../include/TipoItem.hpp"
#include <iostream>

TipoItem::TipoItem()
{
    chave = -1; // indica um item vazio
}
TipoItem::TipoItem(TipoChave c)
{
    chave = c;
}
void TipoItem::SetChave(TipoChave c)
{
    chave = c;
}
TipoChave TipoItem::GetChave()
{
    return chave;
}
void TipoItem::Imprime()
{
    std::cout << chave << std::endl;
}
