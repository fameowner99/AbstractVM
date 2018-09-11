#ifndef OPERAND_HPP

# define OPERAND_HPP

#include "IOperand.hpp"
#include <iostream>
#include "OperandFactory.hpp"

template <typename T>
class Operand: public IOperand
{
	private:
		T				_value;
		eOperandType	_type;
		int 			_precision;
		std::string		_str;
		const OperandFactory *_myFactory;
	public:
	Operand()
	{
	}

	Operand(std::string const &value, eOperandType type, int precision, const OperandFactory *myFactory):
			_type(type), _precision(precision), _myFactory(myFactory)
	{

	}
	Operand(const Operand &tmp)
	{
		*this = tmp;
	}

	Operand &operator=(const Operand &tmp)
	{
		this->_value = tmp._value;
		this->_type = tmp._type;
		this->_precision = tmp._precision;
		this->_str = tmp._str;
	}

	virtual ~Operand()
	{
	}

	int getPrecision()const
	{
		return (_precision);
	}

	eOperandType getType()const
	{
		return (_type);
	}

	IOperand const * operator+(IOperand const & rhs)const
	{

	}

	IOperand const * operator-( IOperand const & rhs )const
	{

	}

	IOperand const * operator*( IOperand const & rhs )const
	{

	}

	IOperand const * operator/( IOperand const & rhs )const
	{

	}

	IOperand const * operator%( IOperand const & rhs )const
	{

	}

	std::string const & toString()const
	{
			return (_str);
	}
};

#endif