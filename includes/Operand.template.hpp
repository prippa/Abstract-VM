#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

# include "Factory.class.hpp"
# include <iostream>
# include <string>
# include <cmath>

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

	T	op_convert(eOperandType const & type, std::string const & value) const
	{
		if (type == Int8)
			return (static_cast<int8_t>(std::stoi(value)));
		else if (type == Int16)
			return (static_cast<int16_t>(std::stoi(value)));
		else if (type == Int32)
			return (std::stoi(value));
		else if (type == Float)
			return (std::stof(value));
		else
			return (std::stod(value));
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
		eOperandType e = rhs.getType();

		return (fac_.createOperand(
			((getPrecision() > rhs.getPrecision() ? type_ : e)),
				std::to_string((value_ + op_convert(e, rhs.toString())))));
	}

	IOperand const * operator-(IOperand const & rhs) const
	{
		eOperandType e = rhs.getType();

		return (fac_.createOperand(
			((getPrecision() > rhs.getPrecision() ? type_ : e)),
				std::to_string((value_ - op_convert(e, rhs.toString())))));
	}

	IOperand const * operator*(IOperand const & rhs) const
	{
		eOperandType e = rhs.getType();

		return (fac_.createOperand(
			((getPrecision() > rhs.getPrecision() ? type_ : e)),
				std::to_string((value_ * op_convert(e, rhs.toString())))));
	}

	IOperand const * operator/(IOperand const & rhs) const
	{
		eOperandType e = rhs.getType();

		return (fac_.createOperand(
			((getPrecision() > rhs.getPrecision() ? type_ : e)),
				std::to_string((value_ / op_convert(e, rhs.toString())))));
	}

	IOperand const * operator%(IOperand const & rhs) const
	{
		eOperandType e = rhs.getType();

		if ((type_ == Float && e == Float) || type_ == Double && e == Double)
			return (fac_.createOperand(
				((getPrecision() > rhs.getPrecision() ? type_ : e)),
					std::to_string(fmod(value_, op_convert(e, rhs.toString())))));
		return (fac_.createOperand(
			((getPrecision() > rhs.getPrecision() ? type_ : e)),
				std::to_string(static_cast<int>(value_)
					% static_cast<int>(op_convert(e, rhs.toString())))));
	}


	bool	operator==(IOperand const & rhs) const
	{ return (value_ == op_convert(rhs.getType(), rhs.toString())); }

	bool	operator>(IOperand const & rhs) const
	{ return (value_ > op_convert(rhs.getType(), rhs.toString())); }

	bool	operator<(IOperand const & rhs) const
	{ return (value_ < op_convert(rhs.getType(), rhs.toString())); }

	std::string const & toString(void) const { return (str_); }
};


#endif
