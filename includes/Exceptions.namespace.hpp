#ifndef EXCEPTIONS_NAMESPACE_HPP
# define EXCEPTIONS_NAMESPACE_HPP

# include <iostream>

namespace Exceptions
{
	class ExceptionEvent final
	{
	public:
		static unsigned int line;

		static std::string	get_invalid_line_number(void);
	private:
		ExceptionEvent(void){}
	};

	class TestError: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
};

#endif
