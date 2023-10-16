#include "../include/FuncoesSatisfabilidade.hpp"
#include "../include/memlog.hpp"

std::string FuncoesSatisfabilidade::AvaliacaoDeSatisfabilidade(std::string formula, std::string stringDeAnalise)
{
    Arvore ArvoreBinaria;

    TipoItem Item;

    Item.setFormula(formula);
    Item.setString(stringDeAnalise);

    ArvoreBinaria.Insere(Item);
    ArvoreBinaria.Caminha(ArvoreBinaria.getRaiz());

    TipoNo *raiz = ArvoreBinaria.getRaiz();

    if (raiz->getItem().getSatisfaz() == true)
        return "1 " + raiz->getItem().getAnalise();
    else
        return "0";
}
