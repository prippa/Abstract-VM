#ifndef COMMANDSEXECUTOR_CLASS_HPP
# define COMMANDSEXECUTOR_CLASS_HPP

# include "Factory.class.hpp"
# include <iostream>
# include <string>
# include <map>

class CommandsExecutor
{
private:
	const Factory	fac_;
public:
	void	ce_execute_command_without_value(std::string const & cmd);
	void	ce_execute_command_with_value(std::string const & cmd,
				std::string const & type,
				std::string const & value);

	CommandsExecutor	&operator=(CommandsExecutor const & rhs);
	CommandsExecutor(CommandsExecutor const & rhs);
	CommandsExecutor(void);
	~CommandsExecutor(void);
};

#endif
