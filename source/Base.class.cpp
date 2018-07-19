#include "../includes/Base.class.hpp"

void	Base::bs_read_from_input(void)
{
	for (std::string line; (std::getline(std::cin, line) && line != ";;");)
		str_.push_back(line);
}

void	Base::bs_read_from_file(char *file_name)
{
	std::ifstream ifs;

	// ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	// try
	// {
		ifs.open(file_name);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	// throw Exceptions::FileOpen();
	// }
	ifs.seekg(0, std::ios::end);
	if (!ifs.is_open() || !ifs.good())
		throw Exceptions::FileOpen();
	for (std::string line; std::getline(ifs, line);)
	{
		std::cout << line << std::endl;
	}
	ifs.close();
}

void	Base::bs_run_calculator(void)
{
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
