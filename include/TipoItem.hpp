#pragma once
#include <iostream>

typedef const char *TipoChave;

class TipoItem
{
private:
    TipoChave chave;
    TipoChave resultado;

public:
    TipoItem()
    {
        chave = ""; // indica um item vazio
        resultado = "";
    };
    TipoItem(TipoChave c)
    {
        chave = c;
    };
    void SetChave(TipoChave c)
    {
        chave = c;
    };
    void SetResultado(TipoChave Resultado)
    {
        resultado = Resultado;
    };
    TipoChave GetChave()
    {
        return chave;
    };
    TipoChave GetResultado()
    {
        return resultado;
    };
    void Imprime()
    {
        std::cout << chave << std::endl;
    };
};
