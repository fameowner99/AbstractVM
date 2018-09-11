#ifndef PARSER_HPP

# define PARSER_HPP

#include "Operand.hpp"
#include <fstream>
#include <regex>
#include <vector>




class Parser
{
	private:
		bool	parseLine(std::string &line);
		void	chooseOperation(std::cmatch &result, int n);
		bool 	check_point(std::string value, std::string type);
		std::vector<const IOperand*> _mystack;
		OperandFactory			_factory;
	public:
		void	readFromFile(char *file);
		void	readFromStandartInput();
		Parser(); // constructor for standart input
		Parser(const Parser&);
		Parser operator=(const Parser&);
		~Parser();
};


#endif