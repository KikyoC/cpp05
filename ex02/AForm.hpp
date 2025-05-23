#pragma once

#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm (const std::string name, const int reqSign, const int reqExec);
		AForm (const AForm &cpy);
		AForm &operator=(const AForm &cpy);
		~AForm();

		virtual std::string getName() const = 0;
		virtual bool isSigned() const = 0;
		virtual int getSignRequirement() const = 0;
		virtual int getExecuteRequirement() const = 0;

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
		
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		virtual void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;	

	private:
		const std::string name;
		bool sign;
		int reqSign;
		int reqExec;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);
