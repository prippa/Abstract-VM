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
	return (nullptr);
}

IOperand const	*Factory::createInt8(std::string const & value) const
{
	return (nullptr);
}

IOperand const	*Factory::createOperand(eOperandType type, std::string const & value) const
{
	return ((this->*func_[type])(value));
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
	func_ = point_to_func_t(TYPE_SIZE);
	func_[Int8] = &Factory::createInt8;
	func_[Int16] = &Factory::createInt16;
	func_[Int32] = &Factory::createInt32;
	func_[Float] = &Factory::createFloat;
	func_[Double] = &Factory::createDouble;
}
Factory::~Factory(void) {}
