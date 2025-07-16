#pragma once

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm();

	private:
		const std::string target;
		virtual void performAction() const;
};

