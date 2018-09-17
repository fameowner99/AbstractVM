#include "../inc/OperandFactory.hpp"
#include "../inc/Operand.hpp"


OperandFactory::OperandFactory()
{
	op_map[Int8] = &OperandFactory::createInt8;
	op_map[Int16] = &OperandFactory::createInt16;
	op_map[Int32] = &OperandFactory::createInt32;
	op_map[Float] = &OperandFactory::createFloat;
	op_map[Double] = &OperandFactory::createDouble;
}


IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const* (OperandFactory::*reference)(std::string const & value) const;
	reference = op_map.at(type);
	return ((*this.*reference)(value));
}

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
	return (new Operand<char>(value, Int8, INT_PRECISION, this));
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
	return (new Operand<short int>(value, Int16, INT_PRECISION, this));
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	return (new Operand<int>(value, Int32, INT_PRECISION, this));
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
	return (new Operand<float>(value, Float, FLOAT_PRECISION, this));
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
	return (new Operand<double>(value, Double, DOUBLE_PRECISION, this));
}

OperandFactory::~OperandFactory() {}