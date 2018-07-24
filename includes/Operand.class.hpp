#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include "IOperand.interface.hpp"

class Operand : public IOperand
{
private:
	eOperandType	type_;
public:
};

#endif
