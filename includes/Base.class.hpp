#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

# include "../includes/Exceptions.namespace.hpp"
# include <iostream>
# include <string>
# include <algorithm>
# include <fstream>
# include <list>
# include <regex>
# include "../includes/Regex.macroses.hpp"
# include "../includes/Factory.class.hpp"

class Base
{
private:
	std::list<std::string>	str_;
	
	bool	is_valid_data_;
	bool	is_exit_command_;

	std::cmatch			result_;
	const std::regex	comment_;
	const std::regex	cmd_;
	const std::regex	cmd_with_value_;

	Factory	create;

	std::list<const IOperand*>	stack_;

	bool	bs_parser(std::string const & str);
public:
	void	bs_read_from_input(void);
	void	bs_read_from_file(char *file_name);
	void	bs_valid_str(void);
	void	bs_run_calculator(void);

	bool	bs_is_valid_data(void);

	Base	&operator=(Base const & obj);
	Base(Base const & obj);
	Base(void);
	~Base(void);
};

#endif
