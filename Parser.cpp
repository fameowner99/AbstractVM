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

bool	Parser::readFromFile(char *file)
{
	std::ifstream fin(file);
	std::string		line;
	int numLine = 1;
	if (fin.fail())
	{
		std::cout << "Wrong file!" << std::endl;
		return (false);
	}
	while (std::getline(fin, line))
	{
		//std::cout << line << std::endl;
		if (!parseLine(line, numLine))
		{
			std::cout << "Line " <<  numLine << " : Error : " << line << std::endl;
			return (false);
		}
		++numLine;
	}
	return (true);
}

bool	Parser::parseLine(std::string &line, int numLine)
{
	commandInfo *inf;
	std::cmatch result;
	std::regex push_assert("([push]{4,4}|[assert]{6,6})([ ]+)([int8]{4,4}|[int16]{5,5}|[int32]{5,5}|[float]{5,5}|[double]{6,6})([(])(-?[0-9]+\\.?[0-9]*)([)])");
	std::regex other("([pop]{3,3}|[dump]{4,4}|[add]{3,3}|[sub]{3,3}|[mul]{3,3}|[div]{3,3}|[mod]{3,3}|[print]{5,5}|[exit]{4,4})");

	if (std::regex_match(line.c_str(), result, other))
	{
		inf = new commandInfo;
		inf->name = result[1];
		inf->number = numLine;
		inf->typeValue = "";
		inf->value = "";
		_commands.push_back(inf);
		return (true);
	}
	else if (std::regex_match(line.c_str(), result, push_assert))
	{

		inf = new commandInfo;
		inf->name = result[1];
		inf->number = numLine;
		inf->typeValue = result[3];
		inf->value = result[5];
		_commands.push_back(inf);
		return (true);
	}
	else if (line == "")
		return (true);
	return (false);
}


bool	Parser::readFromStandartInput()
{
	std::cmatch result;
	std::regex push_assert("([push]{4,4}|[assert]{6,6})([ ]+)([int8]{4,4}|[int16]{5,5}|[int32]{5,5}|[float]{5,5}|[double]{6,6})([(])(-?[0-9]+\\.?[0-9]*)([)])");
	std::regex other("([pop]{3,3}|[dump]{4,4}|[add]{3,3}|[sub]{3,3}|[mul]{3,3}|[div]{3,3}|[mod]{3,3}|[print]{5,5}|[exit]{4,4})");
	std::string	line;
	int 	numLine = 1;

	while (std::getline(std::cin, line))
	{
		if (line == ";;")
			return (true);
		if (!parseLine(line, numLine))
		{
			std::cout << "Line " <<  numLine << " : Error : " << line << std::endl;
			return (false);
		}
		++numLine;
	}
	return (true);
}

std::vector<commandInfo*>		&Parser::getCommands()
{
	return (_commands);
}