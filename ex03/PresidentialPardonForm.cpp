#include "PresidentialPardonForm.hpp"
#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm():
	AForm("presidential pardon", 25, 5),
	target(std::string("random guy"))
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("presidential pardon", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy): AForm(cpy), target(cpy.target)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	AForm::operator=(cpy);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::performAction() const
{
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
}

