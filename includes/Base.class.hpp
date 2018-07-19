#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

# include "../includes/Exceptions.namespace.hpp"
# include <iostream>
# include <fstream>
# include <list>

class Base
{
private:
	std::list<std::string> str_;
public:
	void	bs_read_from_input(void);
	void	bs_read_from_file(char *file_name);
	void	bs_run_calculator(void);

	Base	&operator=(Base const & obj);
	Base(Base const & obj);
	Base(void);
	~Base(void);
};

#endif
