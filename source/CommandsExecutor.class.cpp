#include "../includes/CommandsExecutor.class.hpp"
#include "../includes/Base.class.hpp"
#include "../includes/Regex.macroses.hpp"
#include "../includes/Exceptions.namespace.hpp"
#include <iomanip>

void	CommandsExecutor::ce_del_io(const IOperand ** obj)
{
	delete *obj;
	*obj = nullptr;
}

// --------------------------- Commands Without Value --------------------------
void	CommandsExecutor::ce_pop(Base & bs)
{
	if (bs.stack_.empty())
		throw Exceptions::EmptyStackError(bs.result_[REGEX_CMD_INDEX]);
	right_ = bs.stack_.back();
	bs.stack_.pop_back();
	ce_del_io(&right_);
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
	right_ = bs.stack_.back();
	bs.stack_.pop_back();
	left_ = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left_ + *right_;
	bs.stack_.push_back(res);
	ce_del_io(&left_);
	ce_del_io(&right_);
}

void	CommandsExecutor::ce_sub(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	right_ = bs.stack_.back();
	bs.stack_.pop_back();
	left_ = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left_ - *right_;
	bs.stack_.push_back(res);
	ce_del_io(&left_);
	ce_del_io(&right_);
}

void	CommandsExecutor::ce_mul(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	right_ = bs.stack_.back();
	bs.stack_.pop_back();
	left_ = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left_ * *right_;
	bs.stack_.push_back(res);
	ce_del_io(&left_);
	ce_del_io(&right_);
}

void	CommandsExecutor::ce_div(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	right_ = bs.stack_.back();
	bs.stack_.pop_back();
	left_ = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left_ / *right_;
	bs.stack_.push_back(res);
	ce_del_io(&left_);
	ce_del_io(&right_);
}

void	CommandsExecutor::ce_mod(Base & bs)
{
	if (bs.stack_.size() < CE_MINIMUM_ARGS)
		throw Exceptions::NotEnoughArgumentsError();
	right_ = bs.stack_.back();
	bs.stack_.pop_back();
	left_ = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left_ % *right_;
	bs.stack_.push_back(res);
	ce_del_io(&left_);
	ce_del_io(&right_);
}

void	CommandsExecutor::ce_print(Base & bs)
{
	if (bs.stack_.empty())
		throw Exceptions::EmptyStackError(bs.result_[REGEX_CMD_INDEX]);
	right_ = bs.stack_.back();
	if (right_->getType() != Int8)
	{
		right_ = nullptr;
		throw Exceptions::PrintCommandError();
	}
	int8_t c = static_cast<int8_t>(std::stoi(right_->toString()));
	std::cout << c << std::endl;
	right_ = nullptr;
}

void	CommandsExecutor::ce_exit(Base & bs)
{
	bs.is_exit_command_ = false;
}

void	CommandsExecutor::ce_max(Base & bs)
{
	if (bs.stack_.empty())
		throw Exceptions::EmptyStackError(bs.result_[REGEX_CMD_INDEX]);
	left_ = bs.stack_.front();
	for (auto i = bs.stack_.begin(); i != bs.stack_.end(); ++i)
	{
		right_ = *i;
		if (*left_ < *right_)
			left_ = right_;
	}
	std::cout << left_->toString() << std::endl;
	right_ = nullptr;
	left_ = nullptr;
}

void	CommandsExecutor::ce_min(Base & bs)
{
	if (bs.stack_.empty())
		throw Exceptions::EmptyStackError(bs.result_[REGEX_CMD_INDEX]);
	left_ = bs.stack_.front();
	for (auto i = bs.stack_.begin(); i != bs.stack_.end(); ++i)
	{
		right_ = *i;
		if (*left_ > *right_)
			left_ = right_;
	}
	std::cout << left_->toString() << std::endl;
	right_ = nullptr;
	left_ = nullptr;
}

void	CommandsExecutor::ce_debug(Base & bs)
{
	size_t i8 = 0, i16 = 0, i32 = 0, f = 0, d = 0;
	eOperandType type;
	for (auto i = bs.stack_.begin(); i != bs.stack_.end(); ++i)
	{
		type = (*i)->getType();
		if (type == Int8)
			++i8;
		else if (type == Int16)
			++i16;
		else if (type == Int32)
			++i32;
		else if (type == Float)
			++f;
		else
			++d;
	}
	std::cout << "int8   : " << i8 << std::endl;
	std::cout << "int16  : " << i16 << std::endl;
	std::cout << "int32  : " << i32 << std::endl;
	std::cout << "float  : " << f << std::endl;
	std::cout << "double : " << d << std::endl;
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
	right_ = fac_.createOperand(
		type_[bs.result_[REGEX_TYPE_INDEX]],
		bs.result_[REGEX_VALUE_INDEX]);
	left_ = bs.stack_.back();
	if (!(*right_ == *left_))
	{
		std::string left_str =  left_->toString();
		left_ = nullptr;
		throw Exceptions::AssertError(right_->toString(), left_str);
	}
	left_ = nullptr;
	ce_del_io(&right_);
}

void	CommandsExecutor::ce_less(Base & bs)
{
	if (bs.stack_.empty())
		throw Exceptions::EmptyStackError(bs.result_[REGEX_CMD_INDEX]);
	right_ = fac_.createOperand(
		type_[bs.result_[REGEX_TYPE_INDEX]],
		bs.result_[REGEX_VALUE_INDEX]);
	left_ = bs.stack_.back();
	if (*right_ > *left_)
	{
		std::string left_str =  left_->toString();
		left_ = nullptr;
		throw Exceptions::LessError(right_->toString(), left_str);
	}
	left_ = nullptr;
	ce_del_io(&right_);
}

void	CommandsExecutor::ce_more(Base & bs)
{
	if (bs.stack_.empty())
		throw Exceptions::EmptyStackError(bs.result_[REGEX_CMD_INDEX]);
	right_ = fac_.createOperand(
		type_[bs.result_[REGEX_TYPE_INDEX]],
		bs.result_[REGEX_VALUE_INDEX]);
	left_ = bs.stack_.back();
	if (*right_ < *left_)
	{
		std::string left_str =  left_->toString();
		left_ = nullptr;
		throw Exceptions::MoreError(right_->toString(), left_str);
	}
	left_ = nullptr;
	ce_del_io(&right_);
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

	// Bonus
	cmd_.emplace(CM_MORE, &CommandsExecutor::ce_more);
	cmd_.emplace(CM_LESS, &CommandsExecutor::ce_less);
	cmd_.emplace(CM_MAX, &CommandsExecutor::ce_max);
	cmd_.emplace(CM_MIN, &CommandsExecutor::ce_min);
	cmd_.emplace(CM_DEBUG, &CommandsExecutor::ce_debug);


	cmd_.emplace(CM_PUSH, &CommandsExecutor::ce_push);
	cmd_.emplace(CM_ASSERT, &CommandsExecutor::ce_assert);

	left_ = nullptr;
	right_ = nullptr;
}
CommandsExecutor::~CommandsExecutor(void)
{
	ce_del_io(&left_);
	ce_del_io(&right_);
}
