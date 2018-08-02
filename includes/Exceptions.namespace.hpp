#ifndef EXCEPTIONS_NAMESPACE_HPP
# define EXCEPTIONS_NAMESPACE_HPP

# include <iostream>
# include <string>

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

	class OverflowError: public std::exception
	{
	private:
		std::string	error_;
	public:
		OverflowError(std::string const & str);
		const char	*what(void) const throw();
	};

	class UnderflowError: public std::exception
	{
	private:
		std::string	error_;
	public:
		UnderflowError(std::string const & str);
		const char	*what(void) const throw();
	};

	class NotEnoughArgumentsError: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class AssertError: public std::exception
	{
	private:
		std::string	error_;
	public:
		AssertError(std::string const & right, std::string const & left);
		const char	*what(void) const throw();
	};

	class EmptyStackError: public std::exception
	{
	private:
		std::string	error_;
	public:
		EmptyStackError(std::string const & cmd);
		const char	*what(void) const throw();
	};

	class DivisionByZeroError: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class PrintCommandError: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class MoreError: public std::exception
	{
	private:
		std::string	error_;
	public:
		MoreError(std::string const & right, std::string const & left);
		const char	*what(void) const throw();
	};

	class LessError: public std::exception
	{
	private:
		std::string	error_;
	public:
		LessError(std::string const & right, std::string const & left);
		const char	*what(void) const throw();
	};
};

#endif
