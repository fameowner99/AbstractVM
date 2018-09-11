#include "Operand.hpp"
#include "Parser.hpp"


int			main(int argc, char **argv)
{
	Parser	pr;

	if (argc == 1)
	{
		pr.readFromStandartInput();
	}
	else if (argc == 2)
	{
		pr.readFromFile(argv[1]);
	}
	else if (argc > 2)
		std::cout << "Too many arguments" << std::endl;
	return (0);
}