#include "../inc/Operand.hpp"
#include "../inc/Parser.hpp"



int			main(int argc, char **argv)
{
	try {

		Lexer lex;
		bool parsingIsOk = false;

		if (argc == 1) {
			if (lex.readFromStandartInput())
				parsingIsOk = true;
		} else if (argc == 2) {
			if (lex.readFromFile(argv[1]))
				parsingIsOk = true;
		} else if (argc > 2)
			std::cout << "Too many arguments" << std::endl;
		if (parsingIsOk)
		{
			Parser ab(lex.getCommands());
			if (!ab.getExit())
				throw ParserException("Warning : No EXIT instruction!");
		}
	}
	catch (AvmException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);

}