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
	throw Exceptions::SyntaxError(std::to_string(Exceptions::line), str);
	
	return (true);
}

bool	Base::bs_is_valid_data(void) { return (is_valid_data_); }

void	Base::bs_run_calculator(void)
{
	
}

Base	&Base::operator=(Base const & obj)
{
	if (this != &obj)
		;
	return (*this);
}
Base::Base(Base const & obj) { *this = obj; }
Base::Base(void)
{
	is_valid_data_ = true;
	is_exit_command_ = false;
}
Base::~Base(void) {}
