//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Senhor executor burocrata", 36);
		AForm *f1 = new ShrubberyCreationForm("home");
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
