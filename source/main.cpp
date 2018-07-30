#include "../includes/Base.class.hpp"
#include "../includes/Exceptions.namespace.hpp"

int		main2(int argc, char **argv)
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
		base.bs_valid_str();
		if (base.bs_is_valid_data())
			base.bs_run_calculator();
	}
	catch (const std::exception & e)
	{
		std::cout << "Line " <<  Exceptions::line << " : "<< e.what() << std::endl;
	}
	return (0);
}

int main(int argc, char **argv)
{
	main2(argc, argv);
	system("leaks -q avm");
	return (0);
}
