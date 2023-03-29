//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
	// Form with grade requirements out of bonds ===============================
	try
	{
		Form f1("f1", 0, 30);
//		Form f1("f1", 27, 172);
//		Form f1 ("f1", 0, 234);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// =========================================================================

	// Show Form attributes ====================================================
	std::cout << std::endl;
	Form f2; std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================

	// Bureaucrat without sufficient grade =====================================
	Bureaucrat b1("Senhor Burocrata", 75);
	std::cout << b1 << std::endl; // bureaucrat info
	b1.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================

	// Bureaucrat with sufficient grade ========================================
	Bureaucrat b2("Burocrata melhor", 30);
	std::cout << b2 << std::endl; // bureaucrat info
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================
}
