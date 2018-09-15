#ifndef LEXER_HPP

# define LEXER_HPP

#include "Operand.hpp"
#include "OperandFactory.hpp"
#include "Parser.hpp"

class Lexer
{
private:
	std::vector<const IOperand*> _mystack;
	void	chooseOperation(commandInfo *inf);
	eOperandType chooseOperand(const std::string &str)const;
	void	pushValue(const eOperandType operand, const std::string value);
	OperandFactory			_factory;
	void	lexer(const std::vector<commandInfo*>&)const;
public:
	Lexer();
	Lexer(const std::vector<commandInfo*>&);

};

#endif