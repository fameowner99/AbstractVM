#ifndef LEXER_HPP

# define LEXER_HPP

#include "Operand.hpp"
#include <fstream>
#include <regex>
#include <vector>



struct commandInfo
{
	std::string name;
	std::string typeValue;
	std::string	value;
	int 		number;
};


class Lexer
{
	private:
		bool	lexLine(std::string &line, int numLine);
		std::vector<commandInfo*>		_commands;
		std::vector<commandInfo*>		_errors;
		void	printVectorErrors();
	public:
	std::vector<commandInfo*>&		getCommands();
		bool	readFromFile(char *file);
		bool	readFromStandartInput();
		Lexer();
		Lexer(const Lexer&);
		Lexer operator=(const Lexer&);
		~Lexer();
};


#endif