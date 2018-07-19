#ifndef EXCEPTIONS_NAMESPACE_HPP
# define EXCEPTIONS_NAMESPACE_HPP

# include <iostream>

namespace Exceptions
{
	extern unsigned int line;

	class FileOpen: public std::exception
	{
	private:
		std::string	error_;
	public:
		FileOpen(std::string const & file_name);
		const char	*what(void) const throw();
	};

	class SyntaxError: public std::exception
	{
	private:
		std::string	error_;
	public:
		SyntaxError(std::string const & line, std::string const & str);
		const char	*what(void) const throw();
	};

	class NoExitCommandError: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
};

#endif
