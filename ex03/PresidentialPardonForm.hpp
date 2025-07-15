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

	private:
		const std::string &target;
		virtual void performAction() const;
};

