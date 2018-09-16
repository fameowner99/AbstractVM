#include "Parser.hpp"


bool 	Parser::getExit()
{
	return (_exit);
}

void	Parser::chooseOperation(commandInfo *inf)
{
	if (inf->name.find("pop", 0) != std::string::npos)
	{
		if (_mystack.empty())
			throw ParserException("Error : Can not pop on empty stack!");
		else
		{
			const IOperand *o = _mystack.back();
			_mystack.pop_back();
			delete o;
		}
	}
	else if (inf->name.find("dump", 0) != std::string::npos)
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
	else if (inf->name.find("add", 0) != std::string::npos)
	{
		if (_mystack.size() < 2)
			throw OperationException("Error : There are less than 2 values in stack!");
		const IOperand *o1 = _mystack.back();
		_mystack.pop_back();
		const IOperand *o2 = _mystack.back();
		_mystack.pop_back();
		const IOperand *result = *o1 + *o2;
		_mystack.push_back(result);
		delete o1;
		delete o2;
	}
	else if (inf->name.find("sub", 0) != std::string::npos)
	{
		if (_mystack.size() < 2)
			throw OperationException("Error : There are less than 2 values in stack!");
		const IOperand *o1 = _mystack.back();
		_mystack.pop_back();
		const IOperand *o2 = _mystack.back();
		_mystack.pop_back();
		const IOperand *result = *o2 - *o1;
		_mystack.push_back(result);
		delete o1;
		delete o2;
	}
	else if (inf->name.find("mul", 0) != std::string::npos)
	{
		if (_mystack.size() < 2)
			throw OperationException("Error : There are less than 2 values in stack!");
		const IOperand *o1 = _mystack.back();
		_mystack.pop_back();
		const IOperand *o2 = _mystack.back();
		_mystack.pop_back();
		const IOperand *result = *o1 * *o2;
		_mystack.push_back(result);
		delete o1;
		delete o2;
	}
	else if (inf->name.find("div", 0) != std::string::npos)
	{
		if (_mystack.size() < 2)
			throw OperationException("Error : There are less than 2 values in stack!");
		const IOperand *o1 = _mystack.back();
		_mystack.pop_back();
		const IOperand *o2 = _mystack.back();

		_mystack.pop_back();
		const IOperand *result = *o2 / *o1;
		_mystack.push_back(result);
		delete o1;
		delete o2;
	}
	else if (inf->name.find("mod", 0) != std::string::npos)
	{
		if (_mystack.size() < 2)
			throw OperationException("Error : There are less than 2 values in stack!");
		const IOperand *o1 = _mystack.back();
		_mystack.pop_back();
		const IOperand *o2 = _mystack.back();
		_mystack.pop_back();
		const IOperand *result = *o2 % *o1;
		_mystack.push_back(result);
		delete o1;
		delete o2;
	}
	else if (inf->name.find("print", 0) != std::string::npos)
	{
		if (_mystack.empty())
			throw (ParserException("Error : Can not use print instruction on empty stack!"));
		if (_mystack.back()->getType() != Int8)
			throw (ParserException("Error : Can not use print instruction on not 8-bit integer!"));
		std::cout << static_cast<char>(std::stoi(_mystack.back()->toString())) << std::endl;
	}
	else if (inf->name.find("exit", 0) != std::string::npos)
	{
		_exit = true;
		exit(0);
	}
	else if (inf->name.find("push", 0) != std::string::npos)
	{
		pushValue(chooseOperand(inf->typeValue), inf->value);
	}
	else if (inf->name.find("assert", 0) != std::string::npos)
	{
		if (_mystack.empty())
			throw ParserException("Error : Can not assert on empty stack!");
		const IOperand *o = _mystack.back();
		_mystack.pop_back();
		delete o;
		pushValue(chooseOperand(inf->typeValue), inf->value);
	}
	else if (inf->name.find("reverse", 0) != std::string::npos)
	{
		if (_mystack.empty())
			throw ParserException("Error : Can not reverse an empty stack!");
		reverse(_mystack.begin(), _mystack.end());
		std::cout << "The stack was reversed" << std::endl;
	}

}


void	Parser::pushValue(const eOperandType operand, const std::string value)
{

	_mystack.push_back(_factory.createOperand(operand, value));
}

eOperandType Parser::chooseOperand(const std::string &str)const
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

void	Parser::parser(const std::vector<commandInfo*> &commands)const
{
	for (auto it = commands.begin(); it != commands.end(); ++it)
	{
		const_cast<Parser*>(this)->chooseOperation(*it);
	}

}


Parser::Parser(const std::vector<commandInfo*> &commands): _exit(false)
{
	if (commands.empty())
		throw (ParserException("Error : No instructions!"));
	parser(commands);
}
