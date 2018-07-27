#ifndef INT8_CLASS_HPP
# define INT8_CLASS_HPP

#include "../IOperand.interface.hpp"

class Int8T : public IOperand
{
private:
	static const eOperandType	type_;
	int8_t value_;
	std::string	str_;
public:
	int8_t	get_value(void);

	eOperandType getType(void) const;
	int getPrecision(void) const;

	IOperand const * operator+(IOperand const & rhs) const;
	IOperand const * operator-(IOperand const & rhs) const;
	IOperand const * operator*(IOperand const & rhs) const;
	IOperand const * operator/(IOperand const & rhs) const;
	IOperand const * operator%(IOperand const & rhs) const;

	std::string const & toString(void) const;

	IOperand	&operator=(IOperand const & rhs);
	Int8T(IOperand const & rhs);
	Int8T(std::string const & value);
	~Int8T(void);
};

#endif
