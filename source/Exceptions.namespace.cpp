#include "../includes/Exceptions.namespace.hpp"

unsigned int Exceptions::line = 1;

Exceptions::FileOpen::FileOpen(std::string const & file_name)
{ error_ = "Open File Error - \"" + file_name + "\""; }
const char	*Exceptions::FileOpen::what(void) const throw()
{ return (error_.c_str()); }

Exceptions::SyntaxError::SyntaxError(std::string const & line, std::string const & str)
{ error_ = "Line " + line + " : Syntax Error - \"" + str + "\""; }
const char	*Exceptions::SyntaxError::what(void) const throw()
{ return (error_.c_str()); }

const char	*Exceptions::NoExitCommandError::what(void) const throw()
{ return ("ERROR: no \"exit\" command"); }

Exceptions::OverflowError::OverflowError(std::string const & str)
{ error_ = "ERROR: Overflow on a \"" + str + "\""; }
const char	*Exceptions::OverflowError::what(void) const throw()
{ return (error_.c_str()); }

Exceptions::UnderflowError::UnderflowError(std::string const & str)
{ error_ = "ERROR: Underflow on a \"" + str + "\""; }
const char	*Exceptions::UnderflowError::what(void) const throw()
{ return (error_.c_str()); }

const char	*Exceptions::NotEnoughArgumentsError::what(void) const throw()
{ return ("ERROR: not enough arguments to make arithmetic operation"); }

Exceptions::AssertError::AssertError(std::string const & right, std::string const & left)
{ error_ = "ERROR: assert (" + right + ") is not equal (" + left + ")"; }
const char	*Exceptions::AssertError::what(void) const throw()
{ return (error_.c_str()); }

Exceptions::EmptyStackError::EmptyStackError(std::string const & cmd)
{ error_ = "ERROR: instruction " + cmd + " on an empty stack"; }
const char	*Exceptions::EmptyStackError::what(void) const throw()
{ return (error_.c_str()); }
