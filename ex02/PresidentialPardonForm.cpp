#include "PresidentialPardonForm.hpp"
#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <fstream>
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm(target, 25, 5), target(target)
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

std::string PresidentialPardonForm::getName() const
{
	return AForm::getName();
}

int PresidentialPardonForm::getExecuteRequirement() const
{
	return AForm::getExecuteRequirement();
}

int PresidentialPardonForm::getSignRequirement() const
{
	return AForm::getSignRequirement();
}

bool PresidentialPardonForm::isSigned() const
{
	return AForm::isSigned();
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->isSigned())
		throw FormNotSignedException();
	if (bureaucrat.getGrade() < this->getExecuteRequirement())
		throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << bureaucrat.getName() << std::endl; 
}

