#pragma once

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);
		~PresidentialPardonForm();

		std::string getName() const;
		bool isSigned() const;
		int getSignRequirement() const;
		int getExecuteRequirement() const;

		void execute(const Bureaucrat &bureaucrat) const;

	private:
		const std::string &target;
};

