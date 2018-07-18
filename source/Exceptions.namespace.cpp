#include "../includes/Exceptions.namespace.hpp"

unsigned int Exceptions::ErrorStatus::line = 0;

std::string	Exceptions::ErrorStatus::getErrorMessage(void)
{
	std::string error_str("ERROR line " + std::to_string(line) + " : ");
	return (error_str);
}

const char	*Exceptions::TestError::what(void) const throw()
{
	std::string error_str;
	error_str = "ERROR line " + std::to_string(Exceptions::ErrorStatus::line) + " : ";

	// error_str = Exceptions::ErrorStatus::getErrorMessage();
	return (error_str.c_str());
	// return (static_cast<std::string>(Exceptions::ErrorStatus::getErrorMessage()
	// 	+ "TestsError").c_str());
}
