#ifndef AVM_EXCEPTION_H
# define AVM_EXCEPTION_H

#include <iostream>

class AvmException : public std::exception {

public:

	virtual const char* what() const throw ();
	AvmException();
	AvmException(const AvmException&);
	const AvmException& operator=(const AvmException &);
	virtual ~AvmException() throw ();

private:
	std::string         _msg;

};

#endif