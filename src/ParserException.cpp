#include "../inc/Parser.hpp"

ParserException::ParserException(const std::string& message)
		: AvmException()
		, _msg(message) {
}

const char* ParserException::what() const throw () {
	return _msg.c_str();
}

ParserException::~ParserException() throw () {

}