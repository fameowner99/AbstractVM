#include "Lexer.hpp"


void	Lexer::chooseOperation(commandInfo *inf)
{
	std::cout << "OPERATION IS RIGHT" << std::endl;
	if (inf->name == "pop")
	{
		std::cout << "!!!POP!!!" << std::endl;
	}
	else if (inf->name  == "dump")
	{
		std::cout << "!!!DUMP!!!" << std::endl;
	}
	else if (inf->name  == "add")
	{
		std::cout << "!!!ADD!!!" << std::endl;
	}
	else if (inf->name  == "sub")
	{
		std::cout << "!!!SUB!!!" << std::endl;
	}
	else if (inf->name  == "mul")
	{
		std::cout << "!!!MUL!!!" << std::endl;
	}
	else if (inf->name  == "div")
	{
		std::cout << "!!!DIV!!!" << std::endl;
	}
	else if (inf->name  == "mod")
	{
		std::cout << "!!!MOD!!!" << std::endl;
	}
	else if (inf->name  == "print")
	{
		std::cout << "!!!PRINT!!!" << std::endl;
	}
	else if (inf->name  == "exit")
	{
		std::cout << "!!!EXIT!!!" << std::endl;
	}
	else if (inf->name  == "push")
	{
		std::cout << "!!!PUSH!!!" << std::endl;
		pushValue(chooseOperand(inf->typeValue), inf->value);

	}
	else if (inf->name  == "assert")
	{
		std::cout << "!!!ASSERT!!!" << std::endl;
	}

}

/*for (auto it = _mystack.begin(); it != _mystack.end(); ++it)
{

	std::cout << (*it)->toString()<<std::endl;
}*/

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

	for (auto it = _mystack.begin(); it != _mystack.end(); ++it)
{

	std::cout << (*it)->toString()<<std::endl;
}
}


Lexer::Lexer(const std::vector<commandInfo*> &commands)
{
	lexer(commands);

}