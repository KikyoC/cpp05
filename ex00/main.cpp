#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		Bureaucrat high("High", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Low", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat noob("Noob", 150);
		std::cout << noob << std::endl;
		noob.increment();
		std::cout << noob << std::endl;
		noob.decrement();
		std::cout << noob << std::endl;
		noob.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		boss.decrement();
		std::cout << boss << std::endl;
		boss.increment();
		std::cout << boss << std::endl;
		boss.increment();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
