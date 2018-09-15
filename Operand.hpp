#ifndef OPERAND_HPP

# define OPERAND_HPP

#include "IOperand.hpp"
#include <iostream>
#include "OperandFactory.hpp"
#include <climits>
#include <cfloat>
#include <exception>

template <typename T>
class Operand: public IOperand
{
	private:
		T				_value;
		eOperandType	_type;
		int 			_precision;
		std::string		_str;
		const OperandFactory *_myFactory;
	template <typename Type>
	bool	checkOverflow(Type t, eOperandType type)
	{
		switch (type)
		{
			case Int8:
			{
				return (t <= INT8_MAX && t >= INT8_MIN);
			}
			case Int16:
			{
				return (t <= INT16_MAX && t >= INT16_MIN);
			}
			case Int32:
			{
				return (t <= INT32_MAX && t >= INT32_MIN);
			}
			case Float:
			{
				return (t <= FLT_MAX && t >= FLT_MIN);
			}
			case Double:
			{
				return (t <= DBL_MAX && t >= DBL_MIN);
			}
		}
		return (true);
	}
	public:
	Operand()
	{
	}

	Operand(std::string const &value, eOperandType type, int precision, const OperandFactory *myFactory):
			_type(type), _precision(precision), _myFactory(myFactory), _str(value)
	{
		try
		{

			if (type < Float)
			{
				long long check;
				check = std::stoll(_str);
				if (!checkOverflow<long long>(check, _type))
					throw myex;
				_value = static_cast<T>(check);


			}
			else
			{

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			return ;
		}

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
	class myexception: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Error : Overflow.";
		}
	} myex;

};

#endif