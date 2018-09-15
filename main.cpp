#include "Operand.hpp"
#include "Parser.hpp"
#include "Lexer.hpp"


int			main(int argc, char **argv)
{
	try {


		Parser pr;
		bool parsingIsOk = false;

		if (argc == 1) {
			if (pr.readFromStandartInput())
				parsingIsOk = true;
		} else if (argc == 2) {
			if (pr.readFromFile(argv[1]))
				parsingIsOk = true;
		} else if (argc > 2)
			std::cout << "Too many arguments" << std::endl;
		//DONT FORGET TO DELETE VECTOR OF ALL COMMANDS!!!
		if (parsingIsOk)
			Lexer(pr.getCommands());
	}
	catch (AvmException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}