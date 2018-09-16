#ifndef PARSER_HPP

# define PARSER_HPP

#include "Operand.hpp"
#include "OperandFactory.hpp"
#include "Lexer.hpp"

class Parser
{
private:
	std::vector<const IOperand*> _mystack;
	void	chooseOperation(commandInfo *inf);
	eOperandType chooseOperand(const std::string &str)const;
	void	pushValue(const eOperandType operand, const std::string value);
	OperandFactory			_factory;
	void	parser(const std::vector<commandInfo*>&)const;
	bool 	_exit;
public:
	Parser();
	Parser(const std::vector<commandInfo*>&);
	Parser operator=(const Parser&);
	bool 	getExit();

};

class ParserException: public AvmException
{
public:
	explicit ParserException(const std::string& message)
			: AvmException()
			, _msg(message)
	{

	}
	virtual const char* what() const throw ()
	{
		return _msg.c_str();
	}
	virtual ~ParserException() throw (){}
private:
	std::string			_msg;
};

class OperationException: public AvmException
{
public:
	explicit OperationException(const std::string& message)
			: AvmException()
			, _msg(message)
	{

	}
	virtual const char* what() const throw ()
	{
		return _msg.c_str();
	}
	virtual ~OperationException() throw (){}
private:
	std::string			_msg;
};

#endif