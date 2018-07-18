#include "../includes/Exceptions.namespace.hpp"
#include "../includes/IOperand.interface.hpp"

void	exceptions_func_thrower_4000_00(void)
{
	throw Exceptions::TestError();
}

void	try_catch(void)
{
	try
	{
		exceptions_func_thrower_4000_00();
	}
	catch (std::exception & e)
	{
		std::cout << Exceptions::ExceptionEvent::get_invalid_line_number()
			<< e.what() << std::endl;
	}
}

int		main(int argc, char **argv)
{
	for(size_t i = 0; i < 3; ++i)
	{
		++Exceptions::ExceptionEvent::line;
		try_catch();
	}
	return (0);
}
