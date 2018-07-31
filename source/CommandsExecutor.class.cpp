#include "../includes/CommandsExecutor.class.hpp"
#include "../includes/Base.class.hpp"
#include "../includes/Regex.macroses.hpp"
#include "../includes/Exceptions.namespace.hpp"

// --------------------------- Commands Without Value --------------------------
void	CommandsExecutor::ce_pop(Base & bs)
{
	if (bs.stack_.empty())
		throw Exceptions::EmptyStackError(bs.result_[REGEX_CMD_INDEX]);
	const IOperand *tmp = bs.stack_.back();
	bs.stack_.pop_back();
	delete tmp;
}

void	CommandsExecutor::ce_dump(Base & bs)
{
	for (auto i = bs.stack_.rbegin(); i != bs.stack_.rend(); ++i)
		std::cout << (*i)->toString() << std::endl;
}

void	CommandsExecutor::ce_add(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	const IOperand *left = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *right = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left + *right;
	bs.stack_.push_back(res);
	delete left;
	delete right;
}

void	CommandsExecutor::ce_sub(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	const IOperand *left = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *right = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left - *right;
	bs.stack_.push_back(res);
	delete left;
	delete right;
}

void	CommandsExecutor::ce_mul(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	const IOperand *left = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *right = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left * *right;
	bs.stack_.push_back(res);
	delete left;
	delete right;
}

void	CommandsExecutor::ce_div(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	const IOperand *left = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *right = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left / *right;
	bs.stack_.push_back(res);
	delete left;
	delete right;
}

void	CommandsExecutor::ce_mod(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	const IOperand *left = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *right = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left % *right;
	bs.stack_.push_back(res);
	delete left;
	delete right;
}

void	CommandsExecutor::ce_print(Base & bs)
{

}

void	CommandsExecutor::ce_exit(Base & bs)
{
	bs.is_exit_command_ = false;
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
	if (bs.stack_.empty())
		throw Exceptions::EmptyStackError(bs.result_[REGEX_CMD_INDEX]);
	const IOperand *right = fac_.createOperand(
		type_[bs.result_[REGEX_TYPE_INDEX]],
		bs.result_[REGEX_VALUE_INDEX]);
	const IOperand *left = bs.stack_.back();
	if (*right == *left)
		delete right;
	else
	{
		std::string right_str = right->toString();
		delete right;
		throw Exceptions::AssertError(right_str, left->toString());
	}
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

	cmd_.emplace(CM_POP, &CommandsExecutor::ce_pop);
	cmd_.emplace(CM_DUMP, &CommandsExecutor::ce_dump);
	cmd_.emplace(CM_ADD, &CommandsExecutor::ce_add);
	cmd_.emplace(CM_SUB, &CommandsExecutor::ce_sub);
	cmd_.emplace(CM_MUL, &CommandsExecutor::ce_mul);
	cmd_.emplace(CM_DIV, &CommandsExecutor::ce_div);
	cmd_.emplace(CM_MOD, &CommandsExecutor::ce_mod);
	cmd_.emplace(CM_PRINT, &CommandsExecutor::ce_print);
	cmd_.emplace(CM_EXIT, &CommandsExecutor::ce_exit);

	cmd_.emplace(CM_PUSH, &CommandsExecutor::ce_push);
	cmd_.emplace(CM_ASSERT, &CommandsExecutor::ce_assert);
}
CommandsExecutor::~CommandsExecutor(void) {}
