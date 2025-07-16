#pragma once

#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &cpy);
		~Bureaucrat();

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		std::string getName() const;
		int getGrade() const;
		
		void increment();
		void decrement();
		void signForm(Form &form);	

	private:
		std::string const name;
		int grade;
		void setGrade(int grade);
};

std::ostream &operator<< (std::ostream &os, const Bureaucrat &obj);
