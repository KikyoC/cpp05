#pragma once
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &cpy);
		Intern &operator=(const Intern &cpy);
		~Intern();
		
		AForm *makeForm(const std::string &name, const std::string &target) const;

};
