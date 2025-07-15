#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm (const std::string name, const int reqSign, const int reqExec): name(name), sign(false)
{
	if (reqSign > 150 || reqExec > 150)
		throw GradeTooLowException();
	if (reqSign < 1 || reqExec < 1)
		throw GradeTooHighException();
	this->reqExec = reqExec;
	this->reqSign = reqSign;
}

AForm::AForm (const AForm &cpy): name(cpy.name)
{
	this->reqExec = cpy.reqExec;
	this->reqSign = cpy.reqSign;
	this->sign = false;
}

AForm &AForm::operator=(const AForm &cpy)
{
	if (this != &cpy)
	{
		this->reqExec = cpy.reqExec;
		this->reqSign = cpy.reqSign;
		this->sign = false;
	}
	return *this;
}

AForm::~AForm()
{

}

const std::string &AForm::getName() const
{
	return this->name;
}

bool AForm::isSigned() const
{
	return this->sign;
}

int AForm::getExecuteRequirement() const
{
	return this->reqExec;
}

int AForm::getSignRequirement() const
{
	return this->reqSign;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "AForm name: " << obj.getName() << " require level " << obj.getSignRequirement() << " to be signed and level " << obj.getExecuteRequirement() << " to be executed. It's actually" << (obj.isSigned() ? " " : " not ") << "signed";
	return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->reqSign)
		throw GradeTooLowException();
	this->sign = true;
}

void AForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->sign == false)
		throw FormNotSignedException();
	if (this->reqExec < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->performAction();
}
