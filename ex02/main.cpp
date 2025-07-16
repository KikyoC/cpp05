#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <iostream>

int main()
{
	ShrubberyCreationForm form("home");
	std::cout << "Name is " << form.getName() << std::endl;
	ShrubberyCreationForm cpy = form;
	
	Bureaucrat worker("employee", 138);
	Bureaucrat boss("boss", 1);

	worker.signForm(form);

	worker.executeForm(cpy);

	worker.signForm(cpy);

	worker.executeForm(form);
	boss.executeForm(form);


}
