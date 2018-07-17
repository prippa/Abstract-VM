#include "../includes/avm.hpp"

void	f_swich(eOperandType type)
{
	switch (type)
	{
		case Int8: std::cout << "Int8" << std::endl; break;
		case Int16: std::cout << "Int16" << std::endl; break;
		case Int32: std::cout << "Int32" << std::endl; break;
		case Float: std::cout << "Float" << std::endl; break;
		case Double: std::cout << "Double" << std::endl; break;
		case 6: std::cout << "6" << std::endl; break;
		case 7: std::cout << "7" << std::endl; break;
		case 8: std::cout << "8" << std::endl; break;
		case 9: std::cout << "9" << std::endl; break;
		case 10: std::cout << "10" << std::endl; break;
		case 11: std::cout << "11" << std::endl; break;
		case 12: std::cout << "12" << std::endl; break;
		case 13: std::cout << "13" << std::endl; break;
		case 14: std::cout << "14" << std::endl; break;
		case 15: std::cout << "15" << std::endl; break;
		default: std::cout << "Default" << std::endl; break;
	}
}

void	f_if(eOperandType type)
{
	if (type == Int8)
		std::cout << "Int8" << std::endl;
	else if (type == Int16)
		std::cout << "Int16" << std::endl;
	else if (type == Int32)
		std::cout << "Int32" << std::endl;
	else if (type == Float)
		std::cout << "Float" << std::endl;
	else if (type == Double)
		std::cout << "Double" << std::endl;
	else if (type == 6)
		std::cout << "6" << std::endl;
	else if (type == 7)
		std::cout << "7" << std::endl;
	else if (type == 8)
		std::cout << "8" << std::endl;
	else if (type == 9)
		std::cout << "9" << std::endl;
	else if (type == 10)
		std::cout << "10" << std::endl;
	else if (type == 11)
		std::cout << "11" << std::endl;
	else if (type == 12)
		std::cout << "12" << std::endl;
	else if (type == 13)
		std::cout << "13" << std::endl;
	else if (type == 14)
		std::cout << "14" << std::endl;
	else if (type == 15)
		std::cout << "15" << std::endl;
	else
		std::cout << "Default" << std::endl;
}

int		main(int argc, char **argv)
{
	for(size_t i = 0; i < 200000; ++i)
	{
		f_swich(static_cast<eOperandType>(i % 16));
	}
	return (0);
}
