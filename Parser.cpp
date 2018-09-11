#include "Parser.hpp"

Parser::Parser()
{


}


Parser::Parser(const Parser& tmp)
{
	*this = tmp;
}

Parser Parser::operator=(const Parser&)
{

}

Parser::~Parser()
{

}

void	Parser::readFromFile(char *file)
{
	std::ifstream fin(file);
	std::string		line;
	if (fin.fail())
	{
		std::cout << "Wrong file!" << std::endl;
		return ;
	}
	while (std::getline(fin, line))
	{
		std::cout << line << std::endl;
		parseLine(line);
	}
	for (auto it = _mystack.begin(); it != _mystack.end(); ++it)
	{
		std::cout << (*it)->getPrecision();
	}


}

bool	Parser::parseLine(std::string &line)
{
	std::cmatch result;
	std::regex push_assert("([push]{4,4}|[assert]{6,6})([ ]+)([int8]{4,4}|[int16]{5,5}|[int32]{5,5}|[float]{5,5}|[double]{6,6})([(])(-?[0-9]+\\.?[0-9]*)([)])");
	std::regex other("([pop]{3,3}|[dump]{4,4}|[add]{3,3}|[sub]{3,3}|[mul]{3,3}|[div]{3,3}|[mod]{3,3}|[print]{5,5}|[exit]{4,4})");


	if (std::regex_match(line.c_str(), result, other))
	{
		chooseOperation(result, 1);
		return (true);
	}
	else if (std::regex_match(line.c_str(), result, push_assert))
	{
		//if (check_point(result[5].str(), result[2].str()))
			chooseOperation(result, 5);
		return (true);
	}
	else if (line == "")
		return (true);
	std::cout << "OPERATION IS WRONG" << std::endl;
	return (false);
}

bool 	Parser::check_point(std::string value, std::string type)
{
	if (type != "float" && type != "double" && value.find(".") != std::string::npos)
		return (false);
	return (true);
}

void	Parser::chooseOperation(std::cmatch &result, int n)
{
	std::cout << "OPERATION IS RIGHT" << std::endl;
	if (result[n].str() == "pop")
	{
		std::cout << "!!!POP!!!" << std::endl;
	}
	else if (result[n].str() == "dump")
	{
		std::cout << "!!!DUMP!!!" << std::endl;
	}
	else if (result[n].str() == "add")
	{
		std::cout << "!!!ADD!!!" << std::endl;
	}
	else if (result[n].str() == "sub")
	{
		std::cout << "!!!SUB!!!" << std::endl;
	}
	else if (result[n].str() == "mul")
	{
		std::cout << "!!!MUL!!!" << std::endl;
	}
	else if (result[n].str() == "div")
	{
		std::cout << "!!!DIV!!!" << std::endl;
	}
	else if (result[n].str() == "mod")
	{
		std::cout << "!!!MOD!!!" << std::endl;
	}
	else if (result[n].str() == "print")
	{
		std::cout << "!!!PRINT!!!" << std::endl;
	}
	else if (result[n].str() == "exit")
	{
		std::cout << "!!!EXIT!!!" << std::endl;
	}
	else if (result[1].str() == "push")
	{
		std::cout << "!!!PUSH!!!" << std::endl;

		_mystack.push_back(_factory.createOperand( eOperandType::Int32, result[5]));
	}
	else if (result[1].str() == "assert")
	{
		std::cout << "!!!ASSERT!!!" << std::endl;
	}

}

void	Parser::readFromStandartInput()
{
}