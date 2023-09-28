#include "../include/TADS/Lista/include/ListaDinamica.hpp"
#include "../include/TADS/Lista/include/ListaEstatica.hpp"
#include <iostream>

int main()
{
    ListaEstatica lista_Estatica;
    TipoItem item;

    for (int i = 0; i <= 10; i++)
    {
        item.SetChave(i);
        if (lista_Estatica.GetTamanho() == 0)
        {
            lista_Estatica.InsereInicio(item);
        }
        else
        {
            lista_Estatica.InsereFinal(item);
        }
    }

    lista_Estatica.RemoveFinal();
    lista_Estatica.RemoveInicio();
    lista_Estatica.RemovePosicao(3);
    lista_Estatica.SetItem(5, 3);
    lista_Estatica.InserePosicao(3, 3);

    lista_Estatica.Imprime();
    lista_Estatica.Limpa();
    try
    {
        lista_Estatica.Imprime();
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }

    lista_Estatica.InsereInicio(12);
    lista_Estatica.Imprime();

    ListaDinamica Lista_dim;

    for (int i = 0; i <= 10; i++)
    {
        item.SetChave(i);
        if (Lista_dim.GetTamanho() == 0)
        {
            Lista_dim.InsereInicio(item);
        }
        else
        {
            Lista_dim.InsereFinal(item);
        }
    }

    Lista_dim.RemoveFinal();
    Lista_dim.RemoveInicio();
    Lista_dim.RemovePosicao(3);
    Lista_dim.SetItem(5, 3);
    Lista_dim.InserePosicao(3, 3);

    Lista_dim.Imprime();
    Lista_dim.Limpa();
    try
    {
        Lista_dim.Imprime();
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }

    Lista_dim.InsereInicio(12);
    Lista_dim.Imprime();

    return 0;
}