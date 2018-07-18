#ifndef EXCEPTIONS_NAMESPACE_HPP
# define EXCEPTIONS_NAMESPACE_HPP

# include <iostream>

namespace Exceptions
{
	class ErrorStatus final
	{
	public:
		static unsigned int line;

		static std::string getErrorMessage(void);
	private:
		ErrorStatus(void){}
	};

	class TestError: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
};

#endif
