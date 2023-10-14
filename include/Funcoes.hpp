#pragma once
#include <iostream>
#include "../include/Arvore.hpp"
#include <bits/stdc++.h>
#include "Pilha.hpp"
using namespace std;

namespace FuncoesTP1
{
    bool isOperand(char c)
    {
        // If the character is a digit then it must
        // be an operand
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
    int AvaliacaoDeExpressoes(string exprsn, const char *stringDeAnalise)
    {
        Pilha Stack;

        for (int j = exprsn.size() - 1; j >= 0; j--)
        {

            // Push operand to Stack
            // To convert exprsn[j] to digit subtract
            // '0' from exprsn[j].
            if (isOperand(exprsn[j]))
                Stack.push(exprsn[j] - '0');

            else
            {
                int o1 = 3;
                int o2 = 2;
                if (exprsn[j] == '~')
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
                // Operator encountered
                // Pop two elements from Stack

                // Use switch case to operate on o1
                // and o2 and perform o1 Or o2.
                switch (exprsn[j])
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
    // const char *AvaliacaoDeSatisfabilidade(const char *formula, const char *stringParaAnalisar)
    // {
    //     printf("Teste2");
    //     return "Teste";
    // };

    // Function to check if the character is an operator
    bool isOperator(char c)
    {
        return (!isalpha(c) && !isdigit(c));
    }

    // Function to get the priority of operators
    int getPriority(char C)
    {
        if (C == '|')
            return 1;
        else if (C == '&')
            return 2;
        else if (C == '~')
            return 3;
        return 0;
    }

    // Function to convert the infix expression to postfix
    string infixToPostfix(string infix)
    {
        infix = '(' + infix + ')';
        int l = infix.size();
        Pilha char_stack;
        string output;

        for (int i = 0; i < l; i++)
        {

            // If the scanned character is an
            // operand, add it to output.
            if (isalpha(infix[i]) || isdigit(infix[i]))
                output += infix[i];

            // If the scanned character is an
            // ‘(‘, push it to the stack.
            else if (infix[i] == '(')
                char_stack.push('(');

            // If the scanned character is an
            // ‘)’, pop and output from the stack
            // until an ‘(‘ is encountered.
            else if (infix[i] == ')')
            {
                while (char_stack.top() != '(')
                {
                    output += char_stack.top();
                    char_stack.pop();
                }

                // Remove '(' from the stack
                char_stack.pop();
            }

            // Operator found
            else
            {
                if (isOperator(char_stack.top()))
                {
                    if (infix[i] == '^')
                    {
                        while (
                            getPriority(infix[i]) <= getPriority(char_stack.top()))
                        {
                            output += char_stack.top();
                            char_stack.pop();
                        }
                    }
                    else
                    {
                        while (
                            getPriority(infix[i]) < getPriority(char_stack.top()))
                        {
                            output += char_stack.top();
                            char_stack.pop();
                        }
                    }

                    // Push current Operator on stack
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

    // Function to convert infix to prefix notation
    string infixToPrefix(string infix)
    {
        // Reverse String and replace ( with ) and vice versa
        // Get Postfix
        // Reverse Postfix
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

        // Reverse infix
        reverse(infix.begin(), infix.end());

        // Replace ( with ) and vice versa
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

        // Reverse postfix
        reverse(prefix.begin(), prefix.end());

        return prefix;
    }

}
