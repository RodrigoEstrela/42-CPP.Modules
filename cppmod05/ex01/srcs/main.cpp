//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
	// Bureaucrat without sufficient grade =====================================
	Bureaucrat b1("Senhor Burocrata", 75);
	Form f1;
	try
	{
		f1.beSigned(b1);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << b1.getName() << " couldn't sign " << f1.getName() << " because " << e.what() << std::endl;
	}
	// =========================================================================
}
