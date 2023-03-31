//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
	try // sign: 145 exec: 137
	{
		Bureaucrat b1("Senhor executor burocrata", 150);
		AForm *f1 = new ShrubberyCreationForm("home");
		std::cout << *f1 << std::endl << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
		std::cout << std::endl;
	}
	catch (AForm::FormUnsignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try // sign: 72 exec: 45
	{
		Bureaucrat b1("Senhor doutor", 36);
		AForm *f1 = new RobotomyRequestForm("paciente");
		std::cout << *f1 << std::endl << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
		std::cout << std::endl;
	}
	catch (AForm::FormUnsignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try // sign: 25 exec: 5
	{
		Bureaucrat b1("Burocrata de alto nivel", 3);
		AForm *f1 = new PresidentialPardonForm("krikit warrior");
		std::cout << *f1 << std::endl << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
	}
	catch (AForm::FormUnsignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
