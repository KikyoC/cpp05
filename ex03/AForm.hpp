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
		virtual ~AForm();

		const std::string &getName() const;
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
		
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		virtual void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;	

	private:
		const std::string name;
		bool sign;
		int reqSign;
		int reqExec;
		virtual void performAction() const = 0;;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);
