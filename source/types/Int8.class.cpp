#include "../../includes/types/Int8.class.hpp"

const eOperandType Int8T::type_ = Int8;

eOperandType	Int8T::getType(void) const { return (type_); }
int	Int8T::getPrecision(void) const { return (static_cast<int>(type_)); }
std::string const & Int8T::toString(void) const
{
	return (str_);
}

IOperand const	*Int8T::operator+(IOperand const & rhs) const
{
	return (nullptr);
}

IOperand const	*Int8T::operator-(IOperand const & rhs) const
{
	return (nullptr);
}

IOperand const	*Int8T::operator*(IOperand const & rhs) const
{
	return (nullptr);
}

IOperand const	*Int8T::operator/(IOperand const & rhs) const
{
	return (nullptr);
}

IOperand const	*Int8T::operator%(IOperand const & rhs) const
{
	return (nullptr);
}

int8_t	Int8T::get_value(void) { return(value_); }

IOperand	&Int8T::operator=(IOperand const & rhs)
{
	if (this != &rhs)
		;
	return (*this);
}
Int8T::Int8T(IOperand const & rhs) { *this = rhs; }
Int8T::Int8T(std::string const & value)
: str_(value)
{
	int32_t num = std::stoi(value);

	if (num > INT8_MAX)
		;
	else if (num < INT8_MIN)
		;
	else
		value_ = num;
}
Int8T::~Int8T(void) {}
