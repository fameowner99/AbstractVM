#include "../inc/Lexer.hpp"

Lexer::Lexer()
{


}


Lexer::Lexer(const Lexer& tmp)
{
	*this = tmp;
}

Lexer Lexer::operator=(const Lexer&)
{

	return (*this);
}

Lexer::~Lexer()
{
	freeVectorCommands();
	freeVectorErrors();
}

bool	Lexer::readFromFile(char *file)
{
	std::ifstream fin(file);
	std::string line;
	int numLine = 1;
	if (fin.fail()) {
		std::cout << "Wrong file!" << std::endl;
		return (false);
	}
	while (std::getline(fin, line)) {
		lexLine(line, numLine);
		++numLine;
	}
	if (_errors.empty())
		return (true);
	printVectorErrors();
	return (false);
}

bool	Lexer::lexLine(std::string &line, int numLine)
{
	commandInfo *inf;
	std::cmatch result;
	std::regex push_assert("([push]{4,4}|[assert]{6,6})([ ]+)([int8]{4,4}|[int16]{5,5}|[int32]{5,5}|[float]{5,5}|[double]{6,6})([(])(-?[0-9]+\\.?[0-9]*)([)])([ \n\t]*)");
	std::regex other("((((^;+).*)|[pop]{3,3}|[dump]{4,4}|[add]{3,3}|[sub]{3,3}|[mul]{3,3}|[div]{3,3}|[mod]{3,3}|[print]{5,5}|[exit]{4,4}|[reverse]{7,7})([ \n\t]*))");
	commandInfo *error;

	if (std::regex_match(line.c_str(), result, other))
	{
		if (result[1].str()[0] != ';')
		{
			inf = new commandInfo;
			inf->name = result[1];
			inf->number = numLine;
			inf->typeValue = "";
			inf->value = "";
			_commands.push_back(inf);
		}
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
	else
	{
		error = new commandInfo;
		error->name = line;
		error->number = numLine;
		error->typeValue = "";
		error->value = "";
		_errors.push_back(error);
	}
	return (true);
}


bool	Lexer::readFromStandartInput()
{
	std::cmatch result;
	std::regex push_assert("([push]{4,4}|[assert]{6,6})([ ]+)([int8]{4,4}|[int16]{5,5}|[int32]{5,5}|[float]{5,5}|[double]{6,6})([(])(-?[0-9]+\\.?[0-9]*)([)])([ \n\t]*)");
	std::regex other("(([pop]{3,3}|[dump]{4,4}|[add]{3,3}|[sub]{3,3}|[mul]{3,3}|[div]{3,3}|[mod]{3,3}|[print]{5,5}|[exit]{4,4}|[reverse]{7,7})([ \n\t]*))");
	std::string	line;
	int 	numLine = 1;

	while (std::getline(std::cin, line))
	{
		if (line == ";;")
			break ;
		lexLine(line, numLine);
		++numLine;
	}
	if (_errors.empty())
		return (true);
	printVectorErrors();
	return (false);
}

void	Lexer::printVectorErrors()
{
	for(auto it = _errors.begin(); it != _errors.end(); ++it)
	{
		std::cout << "Line " << (*it)->number << " : Error : " << (*it)->name << std::endl;
	}
	std::cout << std::endl;
	std::cout << "S := INSTR [SEP INSTR]* 	#" << std::endl;
	std::cout << "INSTR :=" << std::endl;
	std::cout << "push VALUE" << std::endl;
	std::cout << "| pop" << std::endl;
	std::cout << "| dump" << std::endl;
	std::cout << "| assert VALUE" << std::endl;
	std::cout << "| add" << std::endl;
	std::cout << "| sub" << std::endl;
	std::cout << "| mul" << std::endl;
	std::cout << "| div" << std::endl;
	std::cout << "| mod" << std::endl;
	std::cout << "| print" << std::endl;
	std::cout << "| exit" << std::endl;
	std::cout << std::endl;
	std::cout << "VALUE :=" << std::endl;
	std::cout << "int8(N)" << std::endl;
	std::cout << "| int16(N)" << std::endl;
	std::cout << "| int32(N)" << std::endl;
	std::cout << "| float(Z)" << std::endl;
	std::cout << "| double(Z)" << std::endl;
	std::cout << std::endl;
	std::cout << "N := [-]?[0..9]+" << std::endl;
	std::cout <<  std::endl;
	std::cout << "Z := [-]?[0..9]+.[0..9]+" << std::endl;
	std::cout << std::endl;
	std::cout << "SEP := '\\n'+" << std::endl;



}

std::vector<commandInfo*>		&Lexer::getCommands()
{
	return (_commands);
}

void	Lexer::freeVectorCommands()
{
	for (const auto& item : _commands)
	{
		delete(item);
	}
	_commands.clear();
}

void	Lexer::freeVectorErrors()
{
	for (const auto& item : _errors)
	{
		delete(item);
	}
	_errors.clear();
}