#include "../inc/Parser.hpp"

OperationException::OperationException(const std::string& message)
		: AvmException()
		, _msg(message) {

}

const char* OperationException::what() const throw () {
	return _msg.c_str();
}

OperationException::~OperationException() throw (){

}