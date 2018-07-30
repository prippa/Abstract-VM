#include "../includes/CommandsExecutor.class.hpp"

CommandsExecutor	&CommandsExecutor::operator=(CommandsExecutor const & rhs)
{
	if (this != &rhs)
		;
	return (*this);
}
CommandsExecutor::CommandsExecutor(CommandsExecutor const & rhs) { *this = rhs; }
CommandsExecutor::CommandsExecutor(void) {}
CommandsExecutor::~CommandsExecutor(void) {}
