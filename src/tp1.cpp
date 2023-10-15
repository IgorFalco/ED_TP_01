#include <iostream>
#include <string.h>
#include "../include/Funcoes.hpp"
#include "../include/FuncoesArvore.hpp"

using namespace FuncoesAvaliacao;
using namespace FuncoesSatisfabilidade;

int main(int argc, char *argv[])
	{

	if (argc != 4)
	{
		std::cerr << "Uso: " << argv[0] << " <string1> <string2> <string3>" << std::endl;
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

	resultado = AvaliacaoDeSatisfabilidade(formula, stringDeAnalise);
	// Imprimindo as strings
	std::cout << resultado << std::endl;

	return 0; // Retorna 0 para indicar sucesso
}