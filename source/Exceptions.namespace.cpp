#include "../includes/Exceptions.namespace.hpp"

unsigned int Exceptions::ExceptionEvent::line = 0;

std::string	Exceptions::ExceptionEvent::get_invalid_line_number(void)
{
	return ("ERROR in Line " + std::to_string(line) + " : ");
}

const char	*Exceptions::TestError::what(void) const throw()
{
	return ("Test Error");
}
