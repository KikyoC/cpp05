#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{

}

Intern::Intern(const Intern &cpy)
{
	(void)cpy;
}

Intern &Intern::operator=(const Intern &cpy)
{
	(void)cpy;
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{

	std::string forms_name[4] = {"presidentialpardon", "robotomyrequest", "shruberrycreation", NULL};
	int i;

	for (i = 0; i < 3 ; i++)
		if (name == forms_name[i])
			break;
	switch (i) {
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			std::cout << "Forn not exists" << std::endl;
			return NULL;
	}
	return NULL;
}
