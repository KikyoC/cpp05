#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():
	name("random form"),
	sign(false),
	reqExec(150),
	reqSign(150)
{}

Form::Form (const std::string name, const int reqSign, const int reqExec):
	name(name),
	sign(false),
	reqExec(reqExec),
	reqSign(reqSign)
{
	if (reqSign > 150 || reqExec > 150)
		throw GradeTooLowException();
	if (reqSign < 1 || reqExec < 1)
		throw GradeTooHighException();
}

Form::Form (const Form &cpy):
	name(cpy.name),
	sign(false),
	reqExec(cpy.reqExec),
	reqSign(cpy.reqSign)
{
}

Form &Form::operator=(const Form &cpy)
{
	if (this != &cpy)
	{
		this->sign = false;
	}
	return *this;
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return this->name;
}

bool Form::isSigned() const
{
	return this->sign;
}

int Form::getExecuteRequirement() const
{
	return this->reqExec;
}

int Form::getSignRequirement() const
{
	return this->reqSign;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}


std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Form name: " << obj.getName() << " require level " << obj.getSignRequirement() << " to be signed and level " << obj.getExecuteRequirement() << " to be executed. It's actually" << (obj.isSigned() ? " " : " not ") << "signed";
	return os;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->reqSign)
		throw GradeTooLowException();
	this->sign = true;
}
