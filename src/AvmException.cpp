#include "../inc/AvmException.hpp"

const char* AvmException::what() const throw () {
	return _msg.c_str();
}

AvmException::AvmException(){

}

AvmException::~AvmException() throw (){

}