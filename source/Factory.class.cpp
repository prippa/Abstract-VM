#include "../includes/Factory.class.hpp"

IOperand const	*Factory::createDouble(std::string const & value) const
{
	return (nullptr);
}

IOperand const	*Factory::createFloat(std::string const & value) const
{
	return (nullptr);
}

IOperand const	*Factory::createInt32(std::string const & value) const
{
	return (nullptr);
}

IOperand const	*Factory::createInt16(std::string const & value) const
{
	std::cout << value << std::endl;
	return (nullptr);
}

IOperand const	*Factory::createInt8(std::string const & value) const
{
	return (nullptr);
}

IOperand const	*Factory::createOperand(eOperandType type, std::string const & value) const
{
	return (nullptr);
}

Factory	&Factory::operator=(Factory const & obj)
{
	if (this != &obj)
		;
	return (*this);
}
Factory::Factory(Factory const & obj) { *this = obj; }
Factory::Factory(void)
{
	func_ = point_to_func_t(VALUE_SIZE);
	func_[Int8] = &createInt8;
	func_[Int16] = &createInt16;
	func_[Int32] = &createInt32;
	func_[Float] = &createFloat;
	func_[Double] = &createDouble;
	std::cout << func_[0] << std::endl;
}
Factory::~Factory(void) {}
