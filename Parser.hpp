#ifndef PARSER_HPP

# define PARSER_HPP

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


class Parser
{
	private:
		bool	parseLine(std::string &line, int numLine);
		std::vector<commandInfo*>		_commands;
	public:
	std::vector<commandInfo*>&		getCommands();
		bool	readFromFile(char *file);
		bool	readFromStandartInput();
		Parser();
		Parser(const Parser&);
		Parser operator=(const Parser&);
		~Parser();
};


#endif