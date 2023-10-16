#include "../include/FuncoesAvaliacao.hpp"

bool FuncoesAvaliacao::ConfereOperador(char c)
{
    // Retorna se for true se for um dígito e false se for um operador
    return isdigit(c);
}
std::string FuncoesAvaliacao::ModificadorDeString(std::string formula, std::string stringParaAnalisar)
{
    std::string novastring = formula;
    std::string valor = " ";
    char iChar1 = ' ';
    char iChar2 = ' ';
    int tamanho = (int)novastring.size();
    for (int i = 0; i <= (int)stringParaAnalisar.size() - 1; i++)
    {
        valor = std::to_string(i);
        iChar1 = valor[0];
        iChar2 = valor[1];

        for (int j = 0; j <= tamanho - 1; j++)
        {
            if (i >= 10)
            {
                if (j != tamanho - 1)
                {

                    if (formula[j] != ' ' && formula[j + 1] != ' ')
                    {
                        if (iChar1 == formula[j] && iChar2 == formula[j + 1])
                        {
                            novastring[j] = stringParaAnalisar[i];
                            novastring[j + 1] = ' ';
                        }
                    }
                }
            }
            else
            {
                if (formula[j] != ' ' && formula[j + 1] == ' ')
                {
                    if (j > 0)
                    {
                        if (iChar1 == formula[j] && formula[j - 1] == ' ')
                            novastring[j] = stringParaAnalisar[i];
                    }
                    else
                    {
                        if (iChar1 == formula[j])
                            novastring[j] = stringParaAnalisar[i];
                    }
                }
            }
        }
    }
    return novastring;
}

int FuncoesAvaliacao::AvaliacaoDeExpressoes(string expressoes)
{
    Pilha Stack;

    for (int j = expressoes.size() - 1; j >= 0; j--)
    {

        // Converte e empilha os dígitos na pilha
        if (FuncoesAvaliacao::ConfereOperador(expressoes[j]))
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

bool FuncoesAvaliacao::SeOperador(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int FuncoesAvaliacao::pegaPrioridade(char C)
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
string FuncoesAvaliacao::infixToPostfix(string infix)
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

string FuncoesAvaliacao::infixToPrefix(string infix)
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

    string prefix = FuncoesAvaliacao::infixToPostfix(infix);

    reverse(prefix.begin(), prefix.end());

    return prefix;
}
