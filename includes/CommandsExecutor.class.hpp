#ifndef COMMANDSEXECUTOR_CLASS_HPP
# define COMMANDSEXECUTOR_CLASS_HPP

# include "Factory.class.hpp"
# include <iostream>
# include <string>
# include <map>

# define CE_MINIMUM_ARGS 2

class Base;

class CommandsExecutor
{
private:
	const Factory	fac_;
	std::map<std::string, eOperandType>								type_;
	std::map<std::string, void (CommandsExecutor::*)(Base & bs)>	cmd_;

	const IOperand * right_;
	const IOperand * left_;

	void		ce_del_io(const IOperand ** obj);
	std::string	ce_format_str(std::string str);

	void	ce_pop(Base & bs);
	void	ce_dump(Base & bs);
	void	ce_add(Base & bs);
	void	ce_sub(Base & bs);
	void	ce_mul(Base & bs);
	void	ce_div(Base & bs);
	void	ce_mod(Base & bs);
	void	ce_print(Base & bs);
	void	ce_exit(Base & bs);
	void	ce_max(Base & bs);
	void	ce_min(Base & bs);
	void	ce_debug(Base & bs);

	void	ce_push(Base & bs);
	void	ce_assert(Base & bs);
	void	ce_more(Base & bs);
	void	ce_less(Base & bs);
public:
	void	ce_execute_command(Base & bs);

	CommandsExecutor	&operator=(CommandsExecutor const & rhs);
	CommandsExecutor(CommandsExecutor const & rhs);
	CommandsExecutor(void);
	~CommandsExecutor(void);
};

#endif
