#ifndef OPERAND_HPP

# define OPERAND_HPP

#define  EPSILON 0.000007

#include "IOperand.hpp"
#include <iostream>
#include "OperandFactory.hpp"
#include <climits>
#include <cfloat>
#include <exception>
#include <sstream>
#include <iomanip>
#include "AvmException.hpp"
#include <cmath>


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
	bool	checkOverflow(Type t, eOperandType type)const
	{
		switch (type)
		{
			case Int8:
			{
				return (t < INT8_MAX && t > INT8_MIN);
			}
			case Int16:
			{
				return (t < INT16_MAX && t >= INT16_MIN);
			}
			case Int32:
			{
				return (t < INT32_MAX && t > INT32_MIN);
			}
			case Float:
			{
				return ((fabs(t) - FLT_MAX < EPSILON) && FLT_MIN - fabsf(t) < EPSILON);
			}
			case Double:
			{
				return ((fabs(t) - DBL_MAX < EPSILON) && DBL_MIN - fabs(t) < EPSILON);
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
		std::stringstream ss(std::ios_base::out);
		if (type < Float)
		{
			long long check;
			check = std::stoll(_str);
			if (!checkOverflow<long long>(check, _type))
				throw OperandException("Error : Overflow or Underflow!");
			_value = static_cast<T>(check);
			ss << std::setprecision(precision) << check;
			_str = ss.str();
		}
		else
		{
			long double check;
			check = std::stold(_str);
			if (!checkOverflow<long double>(check, _type))
				throw OperandException("Error : Overflow or Underflow!");
			_value = static_cast<T>(check);
			ss << std::setprecision(precision) << check;
			_str = ss.str();
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

	IOperand const	*operation(std::string op, IOperand const & rhs)const
	{
		eOperandType type;
		int 		precision;

		type = (this->_type > rhs.getType()) ? _type : rhs.getType();
		precision = (this->_precision > rhs.getPrecision()) ? _precision : rhs.getPrecision();
		std::stringstream ss(std::ios_base::out);
		if (type < Float)
		{
			long long check = 0;
			if (op == "+")
				check = this->_value + std::stoll(rhs.toString());
			else if (op == "-")
				check = this->_value - std::stoll(rhs.toString());
			else if (op == "*")
				check = this->_value * std::stoll(rhs.toString());
			else if (op == "/")
				check = this->_value / std::stoll(rhs.toString());
			else if (op == "%")
				check = std::stoll(this->_str) % std::stoll(rhs.toString());
			if (!checkOverflow<long long>(check, type))
				throw OperandException("Error : Overflow or Underflow!");
			ss << std::setprecision(precision) << check;

		}
		else
		{
			long double check = 0;

			if (op == "+")
				check = this->_value + std::stold(rhs.toString());
			else if (op == "-")
				check = this->_value - std::stold(rhs.toString());
			else if (op == "*")
				check = this->_value * std::stold(rhs.toString());
			else if (op == "/")
				check = this->_value / std::stold(rhs.toString());
			else if (op == "%")
				check = fmod(this->_value , std::stoll(rhs.toString()));
			if (!checkOverflow<long double>(check, type))
				throw OperandException("Error : Overflow or Underflow!");
			ss << std::setprecision(precision) << check;
		}
		return (_myFactory->createOperand(type, ss.str()));
	}

	IOperand const * operator+(IOperand const & rhs)const
	{
		return operation("+", rhs);
	}

	IOperand const * operator-( IOperand const & rhs )const
	{
		return operation("-", rhs);
	}

	IOperand const * operator*( IOperand const & rhs )const
	{
		return operation("*", rhs);
	}

	IOperand const * operator/( IOperand const & rhs )const
	{
		if (std::stold(rhs.toString()) == 0)
			throw OperandException("Error : Division by zero !");
		return operation("/", rhs);
	}

	IOperand const * operator%( IOperand const & rhs )const
	{
		return operation("%", rhs);
	}

	std::string const & toString()const
	{
			return (_str);
	}

	class OperandException: public AvmException
	{
		public:
		OperandException(const std::string& message)
				: AvmException()
				, _msg(message)
		{

		}
		virtual const char* what() const throw ()
		{
			return _msg.c_str();
		}
		virtual ~OperandException() throw (){}
		private:
			std::string			_msg;
	};

};

#endif