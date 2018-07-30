#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

# include "IOperand.interface.hpp"
# include "CommandsExecutor.class.hpp"
# include <iostream>
# include <string>
# include <list>
# include <regex>

class Base
{
	friend class CommandsExecutor;
private:
	std::list<std::string>	str_;
	
	bool	is_valid_data_;
	bool	is_exit_command_;

	std::cmatch			result_;
	const std::regex	comment_;
	const std::regex	cmd_;
	const std::regex	cmd_with_value_;

	std::list<const IOperand *>	stack_;
	CommandsExecutor			cmd_executor_;

	bool	bs_parser(std::string const & str);
public:
	void	bs_read_from_input(void);
	void	bs_read_from_file(char *file_name);
	void	bs_valid_str(void);
	void	bs_run_calculator(void);

	bool	bs_is_valid_data(void);

	Base	&operator=(Base const & rhs);
	Base(Base const & rhs);
	Base(void);
	~Base(void);
};

#endif
