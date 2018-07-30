#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

# include "Factory.class.hpp"
# include <string>

template<typename T>
class Operand : public IOperand
{
private:
	const T				value_;
	const std::string	str_;
	const eOperandType	type_;
	const Factory		fac_;

	eOperandType	op_get_right_type(void)
	{
		if (typeid(int8_t) == typeid(T))
			return (Int8);
		else if (typeid(int16_t) == typeid(T))
			return (Int16);
		else if (typeid(int32_t) == typeid(T))
			return (Int32);
		else if (typeid(float) == typeid(T))
			return (Float);
		else
			return (Double);
	}
public:
	Operand(T value)
	: value_(value), str_(std::to_string(value)), type_(op_get_right_type()) {}
	~Operand(void) {}
	Operand	&operator=(IOperand const & rhs)
	{
		if (this != &rhs)
			;
		return (*this);
	}
	Operand(IOperand const & rhs) { *this = rhs; }


	int getPrecision(void) const { return (static_cast<int>(type_)); }
	eOperandType getType(void) const { return (type_); }


	IOperand const * operator+(IOperand const & rhs) const
	{
		return (nullptr);
	}

	IOperand const * operator-(IOperand const & rhs) const
	{
		return (nullptr);
	}

	IOperand const * operator*(IOperand const & rhs) const
	{
		return (nullptr);
	}

	IOperand const * operator/(IOperand const & rhs) const
	{
		return (nullptr);
	}

	IOperand const * operator%(IOperand const & rhs) const
	{
		return (nullptr);
	}


	std::string const & toString(void) const
	{
		return (str_);
	}
};


#endif
