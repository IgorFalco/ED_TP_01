#include "../include/Arvore.hpp"
#include "../include/FuncoesAvaliacao.hpp"
#include "../include/msgassert.hpp"

Arvore::Arvore()
{
    raiz = nullptr;
}

Arvore::~Arvore()
{
}

void Arvore::Insere(TipoItem item)
{
    InsereRecursivo(raiz, item);
}

void Arvore::InsereRecursivo(TipoNo *&p, TipoItem item)
{
    p = new TipoNo();
    p->item = item;

    /*
        Percorre toda a string binária dada, e a cada inserção substitui o valor dessa string para cada nó.
        Caso seja o nó da direita o valor a ser trocada será '0', caso seja o da esquerda, o valor será '1'.

        No final, ao chegar no último nível, as string serão completamente binárias, sem 'a' nem 'e'.
    */
    for (int i = 0; i <= (int)item.getAnalise().size() - 1; i++)
    {
        char quantificador = item.getAnalise()[i];
        if (quantificador == 'a' || quantificador == 'e')
        {
            p->item.setQuantificadorDaFormula(quantificador);
            TipoItem itemDireita;
            TipoItem itemEsquerda;

            std::string direita = item.getAnalise();
            direita[i] = '0';

            std::string esquerda = item.getAnalise();
            esquerda[i] = '1';

            itemDireita.setString(direita);
            itemDireita.setPosicao(i);
            itemEsquerda.setString(esquerda);
            itemEsquerda.setPosicao(i);

            InsereRecursivo(p->esq, itemEsquerda);
            InsereRecursivo(p->dir, itemDireita);
            break;
        }

        if(quantificador != 'a' && quantificador != 'e' && quantificador != '1' && quantificador != '0')
        {
            erroAssert(false, "A entrada passada possui valores errados");
        }
    }
}

void Arvore::Caminha(TipoNo *p)
{
    if (p != nullptr)
    {

        //PosOrdem

        Caminha(p->esq);
        Caminha(p->dir);

        std::string formula = raiz->item.getFormula();
        formula = FuncoesAvaliacao::ModificadorDeString(formula, p->item.getAnalise());

        size_t pos = formula.find('a');
        size_t pos2 = formula.find('e');

        //Caso não exista quantificadores na fórmula

        if (pos == std::string::npos && pos2 == std::string::npos)
        {

            formula = FuncoesAvaliacao::infixToPrefix(formula);
            int resultado = FuncoesAvaliacao::AvaliacaoDeExpressoes(formula);

            if (resultado == 1)
            {
                p->item.setSatisfaz(true);
            }
            if (resultado == 0)
            {
                p->item.setSatisfaz(false);
            }
        }
        else
        {
            char quantificador = p->item.getQuantificadorDaFormula();

            /*
                Testa todos os casos possíveis:
                a - ambos precisam ser verdadeiros, o valor da string binária na posição será 'a';
                e - qualquer um pode ser verdadeiro, se for o nó da direita, o valor da string binária na posição
                será o valor '0'. Caso o nó da esquerda seja verdadeiro, então o contrário irá acontecer. 
                Se os dois forem verdadeiros, o valor na posição da string binária será 'a'

                Ao chegar na raiz todos os 'a' e 'e' terão sido substituídos!
            */

            if (quantificador == 'a' && (p->dir->item.getSatisfaz() == true && p->esq->item.getSatisfaz() == true))
            {
                std::string stringAnalise = p->item.getAnalise();
                p->item.setSatisfaz(true);
                stringAnalise = p->dir->item.getAnalise();
                stringAnalise[p->dir->item.getPosicao()] = 'a';
                p->item.setString(stringAnalise);
            }

            if (quantificador == 'e' && (p->dir->item.getSatisfaz() == true || p->esq->item.getSatisfaz() == true))
            {
                p->item.setSatisfaz(true);
                std::string stringAnalise = p->item.getAnalise();

                if (p->dir->item.getSatisfaz() == true && p->esq->item.getSatisfaz() == true)
                {
                    stringAnalise = p->dir->item.getAnalise();
                    stringAnalise[p->dir->item.getPosicao()] = 'a';
                    p->item.setString(stringAnalise);

    
                }
                else if (p->dir->item.getSatisfaz() == true && p->esq->item.getSatisfaz() == false)
                {
                    stringAnalise = p->dir->item.getAnalise();
                    stringAnalise[p->dir->item.getPosicao()] = '0';
                    p->item.setString(stringAnalise);
    
                }
                else if (p->dir->item.getSatisfaz() == false && p->esq->item.getSatisfaz() == true)
                {
                    stringAnalise = p->esq->item.getAnalise();
                    stringAnalise[p->esq->item.getPosicao()] = '1';
                    p->item.setString(stringAnalise);
    
                }
            }
        }
    }
}
TipoNo *Arvore::getRaiz()
{
    return raiz;
}

void Arvore::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = nullptr;
}

void Arvore::ApagaRecursivo(TipoNo *p)
{
    if (p != nullptr)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}
