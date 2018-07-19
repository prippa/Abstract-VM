#include "../includes/Base.class.hpp"

void	Base::bs_read_from_input(void)
{
	for (std::string line; (std::getline(std::cin, line) && line != ";;");)
	{
		if (!line.empty() && !std::all_of(line.begin(), line.end(), isspace))
			str_.push_back(line);
	}
}

void	Base::bs_read_from_file(char *file_name)
{
	std::ifstream ifs;

	ifs.open(file_name);
	if (!ifs.is_open())
		throw Exceptions::FileOpen();
	for (std::string line; std::getline(ifs, line);)
	{
		if (!line.empty() && !std::all_of(line.begin(), line.end(), isspace))
			str_.push_back(line);
	}
	ifs.close();
}

void	Base::bs_run_calculator(void)
{
	std::cout << str_.size() << std::endl;
	for (auto i = str_.begin(); i != str_.end(); ++i)
		std::cout << *i << std::endl;
}

Base	&Base::operator=(Base const & obj)
{
	if (this != &obj)
		;
	return (*this);
}
Base::Base(Base const & obj) { *this = obj; }
Base::Base(void) {}
Base::~Base(void) {}
