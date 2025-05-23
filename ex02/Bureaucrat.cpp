#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, const int grade): name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): name(cpy.name), grade(cpy.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	if (this != &cpy)
	{
		this->grade = cpy.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

void Bureaucrat::increment()
{
	this->setGrade(this->grade - 1);
}

void Bureaucrat::decrement()
{
	this->setGrade(this->grade + 1);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw  GradeTooHighException();
	this->grade = grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<< (std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." ;
	return os;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " bacause " << e.what() << std::endl;
	}
}
