//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm* scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "home");

		Bureaucrat b1("jardineiro", 137);
		b1.signForm(*scf);
		b1.executeForm(*scf);
		delete scf;
	}
	catch (Intern::InvalidFormType &e)
	{
		std::cout << "Failed because: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rqf;
		rqf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat b1("DoctorRobotomizer", 45);
		b1.signForm(*rqf);
		b1.executeForm(*rqf);
		delete rqf;
	}
	catch (Intern::InvalidFormType &e)
	{
		std::cout << "Failed because: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "condemned");

		Bureaucrat b1("Presidente", 5);
		b1.signForm(*ppf);
		b1.executeForm(*ppf);
		delete ppf;
	}
	catch (Intern::InvalidFormType &e)
	{
		std::cout << "Failed because: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* wrong;
		wrong = someRandomIntern.makeForm("wrong", "doesn't really matter");

		Bureaucrat b1("burocrata", 1);
		b1.signForm(*wrong);
		b1.executeForm(*wrong);
		delete wrong;
	}
	catch (Intern::InvalidFormType &e)
	{
		std::cout << "Failed because: " << e.what() << std::endl;
	}
}
