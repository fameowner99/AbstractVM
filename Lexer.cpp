#include "Lexer.hpp"


void	Lexer::chooseOperation(commandInfo *inf)
{
	if (inf->name == "pop")
	{
		if (_mystack.empty())
			throw LexerException("Error : Can not pop on empty stack!");
		else
			_mystack.pop_back();
	}
	else if (inf->name  == "dump")
	{
		if (_mystack.empty())
		{
			std::cout << "Stack is empty!" << std::endl;
		}
		else
			{
			reverse(_mystack.begin(), _mystack.end());

			for (auto it = _mystack.begin(); it != _mystack.end(); ++it) {
				std::cout << (*it)->toString() << std::endl;
			}
			reverse(_mystack.begin(), _mystack.end());
			}
	}
	else if (inf->name  == "add")
	{

	}
	else if (inf->name  == "sub")
	{

	}
	else if (inf->name  == "mul")
	{

	}
	else if (inf->name  == "div")
	{

	}
	else if (inf->name  == "mod")
	{

	}
	else if (inf->name  == "print")
	{

	}
	else if (inf->name  == "exit")
	{

	}
	else if (inf->name  == "push")
	{
		pushValue(chooseOperand(inf->typeValue), inf->value);
	}
	else if (inf->name  == "assert")
	{

	}

}


void	Lexer::pushValue(const eOperandType operand, const std::string value)
{

	_mystack.push_back(_factory.createOperand(operand, value));
}

eOperandType Lexer::chooseOperand(const std::string &str)const
{
	if (str == "int8")
	{
		return (Int8);
	}
	else if (str == "int16")
	{
		return (Int16);
	}
	else if (str == "int32")
	{
		return (Int32);
	}
	else if (str == "float")
	{
		return (Float);
	}
	else if (str == "double")
	{
		return (Double);
	}
}
void	Lexer::lexer(const std::vector<commandInfo*> &commands)const
{
	for (auto it = commands.begin(); it != commands.end(); ++it)
	{
		const_cast<Lexer*>(this)->chooseOperation(*it);
	}

}


Lexer::Lexer(const std::vector<commandInfo*> &commands)
{
	lexer(commands);

}