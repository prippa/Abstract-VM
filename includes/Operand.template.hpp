#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

# include "Factory.class.hpp"
# include "Exceptions.namespace.hpp"
# include <iostream>
# include <string>
# include <cmath>

template<typename T>
class Operand : public IOperand
{
	# define SC8	static_cast<int8_t>
	# define SC16	static_cast<int16_t>
	# define SC32	static_cast<int32_t>
	# define SCF	static_cast<float>
	# define SCD	static_cast<double>
private:
	T				value_;
	std::string		str_;
	eOperandType	type_;
	const Factory	fac_;

	eOperandType	op_get_right_type(void) const
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

	T	op_convert(std::string const & value) const
	{
		if (type_ == Int8)
			return (SC8(std::stoi(value)));
		else if (type_ == Int16)
			return (SC16(std::stoi(value)));
		else if (type_ == Int32)
			return (std::stoi(value));
		else if (type_ == Float)
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
		{
			value_ = op_convert(rhs.toString());
			str_ = rhs.toString();
			type_ = rhs.getType();
		}
		return (*this);
	}
	Operand(IOperand const & rhs) { *this = rhs; }

	int					getPrecision(void) const { return (static_cast<int>(type_)); }
	eOperandType		getType(void) const { return (type_); }
	std::string const &	toString(void) const { return (str_); }

	// ------------------------- Arithmetic Operators -------------------------
	IOperand const * operator+(IOperand const & rhs) const
	{
		eOperandType e = (getPrecision() > rhs.getPrecision() ? type_ : rhs.getType());

		if (e == Int8)
			return (fac_.createOperand(e, std::to_string(SC8(value_)
				+ SC8(std::stoi(rhs.toString())))));
		else if (e == Int16)
			return (fac_.createOperand(e, std::to_string(SC16(value_)
				+ SC16(std::stoi(rhs.toString())))));
		else if (e == Int32)
			return (fac_.createOperand(e, std::to_string(SC32(value_)
				+ std::stoi(rhs.toString()))));
		else if (e == Float)
			return (fac_.createOperand(e, std::to_string(SCF(value_)
				+ std::stof(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(SCD(value_)
				+ std::stod(rhs.toString()))));
	}

	IOperand const * operator-(IOperand const & rhs) const
	{
		eOperandType e = (getPrecision() > rhs.getPrecision() ? type_ : rhs.getType());

		if (e == Int8)
			return (fac_.createOperand(e, std::to_string(SC8(value_)
				- SC8(std::stoi(rhs.toString())))));
		else if (e == Int16)
			return (fac_.createOperand(e, std::to_string(SC16(value_)
				- SC16(std::stoi(rhs.toString())))));
		else if (e == Int32)
			return (fac_.createOperand(e, std::to_string(SC32(value_)
				- std::stoi(rhs.toString()))));
		else if (e == Float)
			return (fac_.createOperand(e, std::to_string(SCF(value_)
				- std::stof(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(SCD(value_)
				- std::stod(rhs.toString()))));
	}

	IOperand const * operator*(IOperand const & rhs) const
	{
		eOperandType e = (getPrecision() > rhs.getPrecision() ? type_ : rhs.getType());

		if (e == Int8)
			return (fac_.createOperand(e, std::to_string(SC8(value_)
				* SC8(std::stoi(rhs.toString())))));
		else if (e == Int16)
			return (fac_.createOperand(e, std::to_string(SC16(value_)
				* SC16(std::stoi(rhs.toString())))));
		else if (e == Int32)
			return (fac_.createOperand(e, std::to_string(SC32(value_)
				* std::stoi(rhs.toString()))));
		else if (e == Float)
			return (fac_.createOperand(e, std::to_string(SCF(value_)
				* std::stof(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(SCD(value_)
				* std::stod(rhs.toString()))));
	}

	IOperand const * operator/(IOperand const & rhs) const
	{
		if (std::stod(rhs.toString()) == 0)
			throw Exceptions::DivisionByZeroError();

		eOperandType e = (getPrecision() > rhs.getPrecision() ? type_ : rhs.getType());

		if (e == Int8)
			return (fac_.createOperand(e, std::to_string(SC8(value_)
				/ SC8(std::stoi(rhs.toString())))));
		else if (e == Int16)
			return (fac_.createOperand(e, std::to_string(SC16(value_)
				/ SC16(std::stoi(rhs.toString())))));
		else if (e == Int32)
			return (fac_.createOperand(e, std::to_string(SC32(value_)
				/ std::stoi(rhs.toString()))));
		else if (e == Float)
			return (fac_.createOperand(e, std::to_string(SCF(value_)
				/ std::stof(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(SCD(value_)
				/ std::stod(rhs.toString()))));
	}

	IOperand const * operator%(IOperand const & rhs) const
	{
		if (std::stod(rhs.toString()) == 0)
			throw Exceptions::DivisionByZeroError();

		eOperandType e = (getPrecision() > rhs.getPrecision() ? type_ : rhs.getType());

		if (e == Int8)
			return (fac_.createOperand(e, std::to_string(SC8(value_)
				% SC8(std::stoi(rhs.toString())))));
		else if (e == Int16)
			return (fac_.createOperand(e, std::to_string(SC16(value_)
				% SC16(std::stoi(rhs.toString())))));
		else if (e == Int32)
			return (fac_.createOperand(e, std::to_string(SC32(value_)
				% std::stoi(rhs.toString()))));
		else if (e == Float)
			return (fac_.createOperand(e, std::to_string(std::fmod(SCF(value_),
				std::stof(rhs.toString())))));
		else
			return (fac_.createOperand(e, std::to_string(std::fmod(SCD(value_),
				std::stod(rhs.toString())))));
	}

	// ------------------------- Comparison Operators -------------------------
	bool	operator==(IOperand const & rhs) const
	{
		eOperandType e = (getPrecision() > rhs.getPrecision() ? type_ : rhs.getType());

		if (e == Int8)
			return (SC8(value_) == SC8(std::stoi(rhs.toString())));
		else if (e == Int16)
			return (SC16(value_) == SC16(std::stoi(rhs.toString())));
		else if (e == Int32)
			return (SC32(value_) == std::stoi(rhs.toString()));
		else if (e == Float)
			return (SCF(value_) == std::stof(rhs.toString()));
		else
			return (SCD(value_) == std::stod(rhs.toString()));
	}

	bool	operator>(IOperand const & rhs) const
	{
		eOperandType e = (getPrecision() > rhs.getPrecision() ? type_ : rhs.getType());

		if (e == Int8)
			return (SC8(value_) > SC8(std::stoi(rhs.toString())));
		else if (e == Int16)
			return (SC16(value_) > SC16(std::stoi(rhs.toString())));
		else if (e == Int32)
			return (SC32(value_) > std::stoi(rhs.toString()));
		else if (e == Float)
			return (SCF(value_) > std::stof(rhs.toString()));
		else
			return (SCD(value_) > std::stod(rhs.toString()));
	}

	bool	operator<(IOperand const & rhs) const
	{
		eOperandType e = (getPrecision() > rhs.getPrecision() ? type_ : rhs.getType());

		if (e == Int8)
			return (SC8(value_) < SC8(std::stoi(rhs.toString())));
		else if (e == Int16)
			return (SC16(value_) < SC16(std::stoi(rhs.toString())));
		else if (e == Int32)
			return (SC32(value_) < std::stoi(rhs.toString()));
		else if (e == Float)
			return (SCF(value_) < std::stof(rhs.toString()));
		else
			return (SCD(value_) < std::stod(rhs.toString()));
	}
};

#endif
