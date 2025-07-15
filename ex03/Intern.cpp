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
	return *this;
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{

	std::string forms_name[4] = {"presidentialpardon", "robotomyrequest", "shruberrycreation", ""};
	int i;
	
	AForm *res;

	for (i = 0; !forms_name[i].empty() ; i++)
		if (name == forms_name[i])
			break;
	switch (i) {
		case 0:
			res = new PresidentialPardonForm(target);
			break ;
		case 1:
			res = new RobotomyRequestForm(target);
			break ;
		case 2:
			res = new ShrubberyCreationForm(target);
			break ;
		default:
			std::cout << "Form does not exists" << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << forms_name[i] << std::endl;
	return res;
}
