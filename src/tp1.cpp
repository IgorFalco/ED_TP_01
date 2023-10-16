#include <iostream>
#include <string.h>
#include "../include/msgassert.hpp"
#include "../include/memlog.hpp"
#include "../include/FuncoesAvaliacao.hpp"
#include "../include/FuncoesSatisfabilidade.hpp"

using namespace FuncoesAvaliacao;
using namespace FuncoesSatisfabilidade;

int main(int argc, char *argv[])
{
	// char teste[7] = "tp1_ED";

	// iniciaMemLog(teste);
	// ativaMemLog();

	if (argc != 4)
	{
		erroAssert(false, "Foram passados um número errado de argumentos");
		return 1; // Retorna 1 para indicar um erro
	}

	// Acessando as três strings passadas como argumentos
	std::string operacao = argv[1];
	std::string formula = argv[2];
	std::string stringDeAnalise = argv[3];

	std::string resultado = "";

	if (operacao == "-a")
	{
		std::string PrefixString(ModificadorDeString(formula, stringDeAnalise));
		PrefixString = infixToPrefix(PrefixString);
		resultado = std::to_string(AvaliacaoDeExpressoes(PrefixString));
	}
	else if (operacao == "-s")
	{
		resultado = AvaliacaoDeSatisfabilidade(formula, stringDeAnalise);
	}
	else
	{
		erroAssert(false, "A operacao indicada não está correta");
	}

	// Imprimindo as strings
	std::cout << resultado << std::endl;

	// desativaMemLog();

	// std::cout << finalizaMemLog() << std::endl;

	return 0; // Retorna 0 para indicar sucesso
}