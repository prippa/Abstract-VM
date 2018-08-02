#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

# include "Factory.class.hpp"
# include "Exceptions.namespace.hpp"
# include "Casts.macroses.hpp"
# include <iostream>
# include <string>
# include <cmath>
# include <sstream>
# include <iomanip>

template<typename T>
class Operand : public IOperand
{
private:
	T				value_;
	std::string		str_;
	eOperandType	type_;
	int32_t			precision_;

	void	op_set_types(void)
	{
		if (typeid(int8_t) == typeid(T)) { type_ = Int8; precision_ = 0; }
		else if (typeid(int16_t) == typeid(T)) { type_ = Int16; precision_ = 0; }
		else if (typeid(int32_t) == typeid(T)) { type_ = Int32; precision_ = 0; }
		else if (typeid(float) == typeid(T)) { type_ = Float; precision_ = 7; }
		else { type_ = Double; precision_ = 14; }

		std::stringstream set(std::stringstream::out);
		if (type_ < Float)
			set << std::setprecision(precision_) << SC32(value_);
		else if (type_ == Float)
			set << std::setprecision(precision_) << SCF(value_);
		else
			set << std::setprecision(precision_) << SCD(value_);
		str_ = set.str();
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
	Operand(T value) : value_(value) { op_set_types(); }
	~Operand(void) {}
	Operand	&operator=(IOperand const & rhs)
	{
		if (this != &rhs)
		{
			value_ = op_convert(rhs.toString());
			str_ = rhs.toString();
			type_ = rhs.getType();
			precision_ = rhs.getPrecision();
		}
		return (*this);
	}
	Operand(IOperand const & rhs) { *this = rhs; }

	int					getPrecision(void) const { return (precision_); }
	eOperandType		getType(void) const { return (type_); }
	std::string const &	toString(void) const { return (str_); }

	// ------------------------- Arithmetic Operators -------------------------
	IOperand const * operator+(IOperand const & rhs) const
	{
		eOperandType e = (type_ >= rhs.getType() ? type_ : rhs.getType());

		if (e < Float)
			return (fac_.createOperand(e, std::to_string(SC64(value_)
				+ std::stoll(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(SCLD(value_)
				+ std::stold(rhs.toString()))));
	}

	IOperand const * operator-(IOperand const & rhs) const
	{
		eOperandType e = (type_ >= rhs.getType() ? type_ : rhs.getType());

		if (e < Float)
			return (fac_.createOperand(e, std::to_string(SC64(value_)
				- std::stoll(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(SCLD(value_)
				- std::stold(rhs.toString()))));
	}

	IOperand const * operator*(IOperand const & rhs) const
	{
		eOperandType e = (type_ >= rhs.getType() ? type_ : rhs.getType());

		if (e < Float)
			return (fac_.createOperand(e, std::to_string(SC64(value_)
				* std::stoll(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(SCLD(value_)
				* std::stold(rhs.toString()))));
	}

	IOperand const * operator/(IOperand const & rhs) const
	{
		if (std::stold(rhs.toString()) == 0)
			throw Exceptions::DivisionByZeroError();

		eOperandType e = (type_ >= rhs.getType() ? type_ : rhs.getType());

		if (e < Float)
			return (fac_.createOperand(e, std::to_string(SC64(value_)
				/ std::stoll(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(SCLD(value_)
				/ std::stold(rhs.toString()))));
	}

	IOperand const * operator%(IOperand const & rhs) const
	{
		if (std::stold(rhs.toString()) == 0)
			throw Exceptions::DivisionByZeroError();

		eOperandType e = (type_ >= rhs.getType() ? type_ : rhs.getType());

		if (e < Float)
			return (fac_.createOperand(e, std::to_string(SC64(value_)
				% std::stoll(rhs.toString()))));
		else
			return (fac_.createOperand(e, std::to_string(fmod(SCLD(value_),
				std::stold(rhs.toString())))));
	}

	// ------------------------- Comparison Operators -------------------------
	bool	operator==(IOperand const & rhs) const
	{
		eOperandType e = (type_ >= rhs.getType() ? type_ : rhs.getType());

		if (e < Float)
			return (SC32(value_) == std::stoi(rhs.toString()));
		else if (e == Float)
			return (SCF(value_) == std::stof(rhs.toString()));
		else
			return (SCD(value_) == std::stod(rhs.toString()));
	}

	bool	operator>(IOperand const & rhs) const
	{
		eOperandType e = (type_ >= rhs.getType() ? type_ : rhs.getType());

		if (e < Float)
			return (SC32(value_) > std::stoi(rhs.toString()));
		else if (e == Float)
			return (SCF(value_) > std::stof(rhs.toString()));
		else
			return (SCD(value_) > std::stod(rhs.toString()));
	}

	bool	operator<(IOperand const & rhs) const
	{
		eOperandType e = (type_ >= rhs.getType() ? type_ : rhs.getType());

		if (e < Float)
			return (SC32(value_) < std::stoi(rhs.toString()));
		else if (e == Float)
			return (SCF(value_) < std::stof(rhs.toString()));
		else
			return (SCD(value_) < std::stod(rhs.toString()));
	}
};

#endif
