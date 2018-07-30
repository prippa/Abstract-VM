#include "../includes/CommandsExecutor.class.hpp"
#include "../includes/Base.class.hpp"
#include "../includes/Regex.macroses.hpp"

// --------------------------- Commands Without Value --------------------------
void	CommandsExecutor::ce_pop(Base & bs)
{

}

void	CommandsExecutor::ce_dump(Base & bs)
{

}

void	CommandsExecutor::ce_add(Base & bs)
{

}

void	CommandsExecutor::ce_sub(Base & bs)
{

}

void	CommandsExecutor::ce_mul(Base & bs)
{

}

void	CommandsExecutor::ce_div(Base & bs)
{

}

void	CommandsExecutor::ce_mod(Base & bs)
{

}

void	CommandsExecutor::ce_print(Base & bs)
{

}

void	CommandsExecutor::ce_exit(Base & bs)
{

}
// -----------------------------------------------------------------------------

// --------------------------- Commands With Value -----------------------------
void	CommandsExecutor::ce_push(Base & bs)
{
	bs.stack_.push_back(
		fac_.createOperand(
			type_[bs.result_[REGEX_TYPE_INDEX]],
			bs.result_[REGEX_VALUE_INDEX]));
}

void	CommandsExecutor::ce_assert(Base & bs)
{

}
// -----------------------------------------------------------------------------
void	CommandsExecutor::ce_execute_command(Base & bs)
{
	(this->*cmd_[bs.result_[REGEX_CMD_INDEX]])(bs);
}

CommandsExecutor	&CommandsExecutor::operator=(CommandsExecutor const & rhs)
{
	if (this != &rhs)
		;
	return (*this);
}
CommandsExecutor::CommandsExecutor(CommandsExecutor const & rhs) { *this = rhs; }
CommandsExecutor::CommandsExecutor(void)
{
	type_.emplace(TP_INT8, Int8);
	type_.emplace(TP_INT16, Int16);
	type_.emplace(TP_INT32, Int32);
	type_.emplace(TP_FLOAT, Float);
	type_.emplace(TP_DOUBLE, Double);

	cmd_.emplace(CM_POP, ce_pop);
	cmd_.emplace(CM_DUMP, ce_dump);
	cmd_.emplace(CM_ADD, ce_add);
	cmd_.emplace(CM_SUB, ce_sub);
	cmd_.emplace(CM_MUL, ce_mul);
	cmd_.emplace(CM_DIV, ce_div);
	cmd_.emplace(CM_MOD, ce_mod);
	cmd_.emplace(CM_PRINT, ce_print);
	cmd_.emplace(CM_EXIT, ce_exit);

	cmd_.emplace(CM_PUSH, ce_push);
	cmd_.emplace(CM_ASSERT, ce_assert);
}
CommandsExecutor::~CommandsExecutor(void) {}
