#include "../includes/Exceptions.namespace.hpp"
#include "../includes/IOperand.interface.hpp"

void	exceptions_func_thrower_4000_00(void)
{
	std::cout << "1" << std::endl;
	throw Exceptions::TestError();
	std::cout << "2" << std::endl;
}

int		main(int argc, char **argv)
{
	// std::string str = "ERROR line " + std::to_string(0) + " : " + "Test Error";
	// std::cout << str.c_str() << std::endl;
	try
	{
		exceptions_func_thrower_4000_00();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
