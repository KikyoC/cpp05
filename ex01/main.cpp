#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
	Bureaucrat noob("Noob", 150);
	Bureaucrat boss("Boss", 1);
	
	Form president("Kill president", 100, 1);
	
	noob.signForm(president);
	boss.signForm(president);

	Form newPresident = president;

	Bureaucrat employee("Random employee", 100);
	employee.signForm(newPresident);

	//Basic tests
	try {
		Form invalid("Invalid", 200, 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl; 
	}

	try {
		Form invalid("Invalid", 0, 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl; 
	}
	try {
		Form invalid("Invalid", 1, 200);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl; 
	}

	try {
		Form invalid("Invalid", 1, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl; 
	}

}
