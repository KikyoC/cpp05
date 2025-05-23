#include "ShrubberyCreationForm.hpp"
#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("shruberry", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy): AForm(cpy), target(cpy.target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	AForm::operator=(cpy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

std::string ShrubberyCreationForm::getName() const
{
	return AForm::getName();
}

int ShrubberyCreationForm::getExecuteRequirement() const
{
	return AForm::getExecuteRequirement();
}

int ShrubberyCreationForm::getSignRequirement() const
{
	return AForm::getSignRequirement();
}

bool ShrubberyCreationForm::isSigned() const
{
	return AForm::isSigned();
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->isSigned())
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > this->getExecuteRequirement())
		throw GradeTooLowException();
	std::string str = this->target + "_shrubbery";
	std::ofstream file(str.c_str());

	file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _    ^" << std::endl;
    file << "  _ -  | |   -_   / \\" << std::endl;
    file << "      // \\\\        |" << std::endl;
}
