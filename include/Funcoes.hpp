#pragma once
#include <iostream>
#include "../include/Arvore.hpp"
#include <bits/stdc++.h>
#include "Pilha.hpp"
using namespace std;

namespace FuncoesTP1
{
    bool ConfereOperador(char c)
    {
        // Retorna se for ture se for um dígito e false se for um operador
        return isdigit(c);
    }
    const char *ModificadorDeString(const char *formula, const char *stringParaAnalisar)
    {
        char *novastring = new char[strlen(formula) + 1];
        strcpy(novastring, formula);
        for (int i = 0; i <= (int)strlen(stringParaAnalisar); i++)
        {
            char iChar = i + '0';

            for (int j = 0; j <= (int)strlen(novastring); j++)
            {
                if (iChar == formula[j])
                    novastring[j] = stringParaAnalisar[i];
            }
        }
        return novastring;
    }
    int AvaliacaoDeExpressoes(string expressoes, const char *stringDeAnalise)
    {
        Pilha Stack;

        for (int j = expressoes.size() - 1; j >= 0; j--)
        {

            // Converte e empilha os dígitos na pilha
            if (ConfereOperador(expressoes[j]))
                Stack.push(expressoes[j] - '0');

            else
            {
                int o1;
                int o2;
                if (expressoes[j] == '~')
                {
                    o1 = Stack.top();
                    Stack.pop();
                }
                else
                {
                    o1 = Stack.top();
                    Stack.pop();
                    o2 = Stack.top();
                    Stack.pop();
                }
                // Se encontrar operadores
                // Exclui os dois últimos itens da pilha

                switch (expressoes[j])
                {
                case '|':
                    Stack.push(o1 || o2);
                    break;
                case '&':
                    Stack.push(o1 & o2);
                    break;
                case '~':
                    Stack.push(!o1);
                    break;
                }
            }
        }

        return Stack.top();
    }






    

    /* O código abaixo contém funções que irão transformar a fórmula da operação para o tipo
       prefixado, desse modo facilitando na hora de avaliar as expressões!
    */

    bool SeOperador(char c)
    {
        return (!isalpha(c) && !isdigit(c));
    }

    int pegaPrioridade(char C)
    {
        if (C == '|')
            return 1; // menor prioridade
        else if (C == '&')
            return 2;
        else if (C == '~')
            return 3; // maior prioridade
        return 0;
    }

    // Converte expressoes infix para postfix
    string infixToPostfix(string infix)
    {
        infix = '(' + infix + ')';
        int l = infix.size();
        Pilha char_stack;
        string output;

        for (int i = 0; i < l; i++)
        {

            // Se o caractere for um operador
            // adicione em output
            if (isalpha(infix[i]) || isdigit(infix[i]))
                output += infix[i];

            else if (infix[i] == '(')
                char_stack.push('(');

            else if (infix[i] == ')')
            {
                while (char_stack.top() != '(')
                {
                    output += char_stack.top();
                    char_stack.pop();
                }

                // Remove '(' da pilha
                char_stack.pop();
            }
            else
            {
                if (SeOperador(char_stack.top()))
                {
                    if (infix[i] == '~')
                    {
                        while (
                            pegaPrioridade(infix[i]) <= pegaPrioridade(char_stack.top()))
                        {
                            output += char_stack.top();
                            char_stack.pop();
                        }
                    }
                    else
                    {
                        while (
                            pegaPrioridade(infix[i]) < pegaPrioridade(char_stack.top()))
                        {
                            output += char_stack.top();
                            char_stack.pop();
                        }
                    }

                    // Empilha o operador na pilha
                    char_stack.push(infix[i]);
                }
            }
        }
        while (!char_stack.empty())
        {
            output += char_stack.top();
            char_stack.pop();
        }
        return output;
    }

    string infixToPrefix(string infix)
    {

        std::string stringSemEspacos;
        for (char caractere : infix)
        {
            if (!std::isspace(caractere))
            {
                stringSemEspacos += caractere;
            }
        }
        infix = stringSemEspacos;

        int l = infix.size();

        reverse(infix.begin(), infix.end());

        for (int i = 0; i < l; i++)
        {

            if (infix[i] == '(')
            {
                infix[i] = ')';
            }
            else if (infix[i] == ')')
            {
                infix[i] = '(';
            }
        }

        string prefix = infixToPostfix(infix);

        reverse(prefix.begin(), prefix.end());

        return prefix;
    }

}
