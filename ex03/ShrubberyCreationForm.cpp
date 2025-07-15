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

void ShrubberyCreationForm::performAction() const
{
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
