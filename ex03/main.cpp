#include <Bureaucrat.hpp>
#include <Intern.hpp>
#include <ShrubberyCreationForm.hpp>

int main()
{
	Intern intern;

	AForm *form = intern.makeForm("robotomyrequest", "boss");
	
	Bureaucrat worker("employee", 138);
	Bureaucrat boss("boss", 1);

	worker.signForm(*form);

	worker.executeForm(*form);
	boss.executeForm(*form);

	delete form;


}
