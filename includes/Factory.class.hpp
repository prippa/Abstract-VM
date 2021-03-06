#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

# include "IOperand.interface.hpp"
# include <vector>

namespace FactoryClass
{
	class Factory
	{
		typedef std::vector<IOperand const *(Factory::*)(std::string const & value) const> point_to_func_t;
	private:
		point_to_func_t func_;

		IOperand const	*createInt8(std::string const & value) const;
		IOperand const	*createInt16(std::string const & value) const;
		IOperand const	*createInt32(std::string const & value) const;
		IOperand const	*createFloat(std::string const & value) const;
		IOperand const	*createDouble(std::string const & value) const;
	public:
		IOperand const	*createOperand(eOperandType type, std::string const & value) const;

		Factory	&operator=(Factory const & rhs);
		Factory(Factory const & rhs);
		Factory(void);
		~Factory(void);
	};
}

extern const FactoryClass::Factory fac_;

#endif
