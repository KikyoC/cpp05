#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>

int main()
{
	ShrubberyCreationForm form("home");
	ShrubberyCreationForm cpy = form;
	
	Bureaucrat worker("employee", 138);
	Bureaucrat boss("boss", 1);

	worker.signForm(form);

	worker.executeForm(cpy);

	worker.signForm(cpy);

	worker.executeForm(form);
	boss.executeForm(form);


}
