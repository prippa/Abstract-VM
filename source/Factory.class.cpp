#include "../includes/Factory.class.hpp"
#include "../includes/Operand.template.hpp"
#include "../includes/Exceptions.namespace.hpp"

IOperand const	*Factory::createDouble(std::string const & value) const
{
	return (new Operand<double>(std::stod(value)));
}

IOperand const	*Factory::createFloat(std::string const & value) const
{
	return (new Operand<float>(std::stof(value)));
}

IOperand const	*Factory::createInt32(std::string const & value) const
{
	// std::cout << "!!!" << value << std::endl;
	// long long a = std::stoll("13122312");
	// int64_t b;
	return (new Operand<int32_t>(std::stoi(value)));
}

IOperand const	*Factory::createInt16(std::string const & value) const
{
	int32_t num = std::stoi(value);

	if (num > INT16_MAX)
		throw Exceptions::OverflowError("Int16");
	else if (num < INT16_MIN)
		throw Exceptions::UnderflowError("Int16");
	else
		return (new Operand<int16_t>(static_cast<int16_t>(num)));
}

IOperand const	*Factory::createInt8(std::string const & value) const
{
	int32_t num = std::stoi(value);

	if (num > INT8_MAX)
		throw Exceptions::OverflowError("Int8");
	else if (num < INT8_MIN)
		throw Exceptions::UnderflowError("Int8");
	else
		return (new Operand<int8_t>(static_cast<int8_t>(num)));
}

IOperand const	*Factory::createOperand(eOperandType type, std::string const & value) const
{
	return ((this->*func_[type])(value));
}

Factory	&Factory::operator=(Factory const & rhs)
{
	if (this != &rhs)
		;
	return (*this);
}
Factory::Factory(Factory const & rhs) { *this = rhs; }
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
