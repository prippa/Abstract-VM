#include "../includes/Base.class.hpp"

void	Base::bs_read_from_input(void)
{
	for (std::string line; (std::getline(std::cin, line) && line != ";;");)
		str_.push_back(line);
}

void	Base::bs_read_from_file(char *file_name)
{
	std::ifstream ifs;

	ifs.open(file_name);
	if (!ifs.is_open())
		throw Exceptions::FileOpen(file_name);
	for (std::string line; std::getline(ifs, line);)
		str_.push_back(line);
	ifs.close();
}

void	Base::bs_valid_str(void)
{
	for (auto i = str_.begin(); i != str_.end(); ++i)
	{
		try
		{
			if (!bs_parser(*i))
				break;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	if (!is_exit_command_)
		throw Exceptions::NoExitCommandError();
}

bool	Base::bs_parser(std::string const & str)
{
	++Exceptions::line;
	if (str.empty() || std::all_of(str.begin(), str.end(), isspace))
		return (true);
	if (std::regex_match(str.c_str(), result_, cmd_))
	{
		if (result_[REGEX_CMD_INDEX] == "exit")
		{
			is_exit_command_ = true;
			return (false);
		}
		return (true);
	}
	else if (std::regex_match(str.c_str(), comment_)
		|| std::regex_match(str.c_str(), cmd_with_value_))
		return (true);
	else
	{
		is_valid_data_ = false;
		throw Exceptions::SyntaxError(std::to_string(Exceptions::line), str);
	}
}

bool	Base::bs_is_valid_data(void) { return (is_valid_data_); }

void	Base::bs_run_calculator(void)
{
	std::cout << "RUN CALCUL" << std::endl;
}

Base	&Base::operator=(Base const & obj)
{
	if (this != &obj)
		;
	return (*this);
}
Base::Base(Base const & obj) { *this = obj; }
Base::Base(void)
: comment_(REGEX_COMMENT_ALWAYS), cmd_(REGEX_CMD), cmd_with_value_(REGEX_CMD_WITH_VALUE)
{
	is_valid_data_ = true;
	is_exit_command_ = false;
}
Base::~Base(void) {}
