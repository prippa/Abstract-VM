#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

# include "../includes/Exceptions.namespace.hpp"
# include <iostream>
# include <string>
# include <algorithm>
# include <fstream>
# include <list>
# include <regex>

# define REGEX_CMD_INDEX 2
# define REGEX_SPACES "([\\s]*)"
# define REGEX_COMMENT_ALWAYS "((;)(.*))"
# define REGEX_COMMENT_NOT_ALWAYS "(((;)(.*))|([]{0,0}))"
# define REGEX_CMD REGEX_SPACES "((pop)|(dump)|(add)|(sub)|(mul)|(div)|(mod)|(print)|(exit))" REGEX_SPACES
# define REGEX_NUM "(\\()(([\\d]*)|(([\\d]*)|(([\\d]*)(\\.)[\\d]*)))(\\))"
# define REGEX_CMD_WITH_VALUE REGEX_SPACES "((push)|(assert))" REGEX_SPACES "((int8)|(int16)|(int32)|(float)|(double))" REGEX_NUM REGEX_SPACES

class Base
{
private:
	std::list<std::string>	str_;
	bool	is_valid_data_;
	bool	is_exit_command_;

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
