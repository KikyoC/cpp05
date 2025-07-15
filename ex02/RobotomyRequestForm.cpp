#include "RobotomyRequestForm.hpp"
#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <csignal>
#include <cstdlib>
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("robotomy", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy): AForm(cpy), target(cpy.target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	AForm::operator=(cpy);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::performAction() const
{
	std::srand(time(0));
	int random = std::rand() % 2;
	if (random)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << "Failed to robotomize " << target << std::endl;
}
