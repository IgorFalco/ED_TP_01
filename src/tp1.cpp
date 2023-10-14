#include <iostream>
#include <string.h>
#include "../include/Funcoes.hpp"

int main(int argc, char *argv[])
{

	if (argc != 4)
	{
		std::cerr << "Uso: " << argv[0] << " <string1> <string2> <string3>" << std::endl;
		return 1; // Retorna 1 para indicar um erro
	}

	// Acessando as três strings passadas como argumentos
	std::string operacao = argv[1];
	const char *formula = argv[2];
	const char *stringDeAnalise = argv[3];

	int result = 2;

	std::string PrefixString(FuncoesTP1::ModificadorDeString(formula, stringDeAnalise));
	PrefixString = FuncoesTP1::infixToPrefix(PrefixString);

	if (operacao == "-a")
	{
		result = FuncoesTP1::AvaliacaoDeExpressoes(PrefixString, stringDeAnalise);
	}
	else if (operacao == "-s")
	{
		// FuncoesTP1::AvaliacaoDeSatisfabilidade(formula, stringDeAnalise);
	}

	// Imprimindo as strings
	std::cout << result << std::endl;

	return 0; // Retorna 0 para indicar sucesso
}