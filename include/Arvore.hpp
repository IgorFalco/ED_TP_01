#pragma once
#include "TipoNo.hpp"
#include "Funcoes.hpp"

bool ConfereOperador(char c)
{
    // Retorna se for true se for um dígito e false se for um operador
    return isdigit(c);
}
class Arvore
{
public:
    Arvore();
    ~Arvore();

    void Insere(TipoItem Item);
    void Caminha(TipoNo *p);
    void Caminha(int tipo);
    void Limpa();
    TipoNo *getRaiz();

private:
    void InsereRecursivo(TipoNo *&p, TipoItem Item);
    void ApagaRecursivo(TipoNo *p);

    TipoNo *raiz;
};

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

    for (int i = 0; i <= (int)item.getAnalise().size(); i++)
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
    }
}

void Arvore::Caminha(TipoNo *p)
{
    if (p != nullptr)
    {
        Caminha(p->esq);
        Caminha(p->dir);

        std::string formula = raiz->item.getFormula();
        formula = FuncoesAvaliacao::ModificadorDeString(formula, p->item.getAnalise());

        size_t pos = formula.find('a');
        size_t pos2 = formula.find('e');

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
