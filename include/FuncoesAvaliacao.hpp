#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include "Pilha.hpp"
using namespace std;

namespace FuncoesAvaliacao
{
    bool ConfereOperador(char c);
    std::string ModificadorDeString(std::string formula, std::string stringParaAnalisar);

    int AvaliacaoDeExpressoes(string expressoes);

    /* O código abaixo contém funções que irão transformar a fórmula da operação para o tipo
       prefixado, desse modo facilitando na hora de avaliar as expressões!
    */

    bool SeOperador(char c);

    int pegaPrioridade(char C);

    // Converte expressoes infix para postfix
    string infixToPostfix(string infix);

    string infixToPrefix(string infix);
}
