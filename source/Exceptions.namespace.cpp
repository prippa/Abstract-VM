#include "../includes/Exceptions.namespace.hpp"

unsigned int Exceptions::ErrorStatus::line = 0;

std::string	Exceptions::ErrorStatus::getErrorMessage(void)
{
	return ("ERROR line " + std::to_string(line) + " : ");
}

const char	*Exceptions::TestError::what(void) const throw()
{
	return (static_cast<std::string>(Exceptions::ErrorStatus::getErrorMessage()
		+ "TestsError").c_str());
}
