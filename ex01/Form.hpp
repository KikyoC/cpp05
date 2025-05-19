#pragma once

#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
	public:
		Form (const std::string name, const int reqSign, const int reqExec);
		Form (const Form &cpy);
		Form &operator=(const Form &cpy);
		~Form();

		std::string getName() const;
		bool isSigned() const;
		int getSignRequirement() const;
		int getExecuteRequirement() const;

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
		
		void beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string name;
		bool sign;
		int reqSign;
		int reqExec;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);
