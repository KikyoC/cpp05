#pragma once

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm();

		std::string getName() const;
		bool isSigned() const;
		int getSignRequirement() const;
		int getExecuteRequirement() const;

		void execute(const Bureaucrat &bureaucrat) const;
	private:
		const std::string &target;
};

