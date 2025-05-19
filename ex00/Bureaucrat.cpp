#include "Bureaucrat.hpp"

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
