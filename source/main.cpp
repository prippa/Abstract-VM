#include "../includes/Base.class.hpp"

int		main(int argc, char **argv)
{
	Base base;

	try
	{
		if (argc == 1)
			base.bs_read_from_input();
		else if (argc == 2)
			base.bs_read_from_file(argv[1]);
		else
		{
			std::cout << "Incorrect Use!" << std::endl;
			return (-1);
		}
		base.bs_run_calculator();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
