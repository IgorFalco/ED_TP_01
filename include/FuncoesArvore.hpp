#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include "Arvore.hpp"
using namespace std;

namespace FuncoesSatisfabilidade
{
    std::string AvaliacaoDeSatisfabilidade(std::string formula, std::string stringDeAnalise)
    {
        Arvore ArvoreDeSatisfabilidade;

        TipoItem ItemTesteSatisfabilidade;

        ItemTesteSatisfabilidade.setFormula(formula);
        ItemTesteSatisfabilidade.setString(stringDeAnalise);

        ArvoreDeSatisfabilidade.Insere(ItemTesteSatisfabilidade);
        ArvoreDeSatisfabilidade.Caminha(ArvoreDeSatisfabilidade.getRaiz());

        TipoNo *raiz = ArvoreDeSatisfabilidade.getRaiz();

        if (raiz->getItem().getSatisfaz() == true)
            return "1 " + raiz->getItem().getAnalise();
        else
            return "0";
    }
}
