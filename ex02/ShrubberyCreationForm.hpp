#pragma once

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm();

		std::string getName() const;
		bool isSigned() const;
		int getSignRequirement() const;
		int getExecuteRequirement() const;

		void execute(const Bureaucrat &bureaucrat) const;

	private:
		const std::string &target;

};

