//
// Created by rdas-nev on 3/31/23.
//

#ifndef INC_42_CPP_MODULES_INTERN_H
#define INC_42_CPP_MODULES_INTERN_H

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
		std::string nothingspecial;
	public:
	// Orthodox Canonical Form
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();
	// Make form
		AForm *makeForm(std::string name, std::string target);
	// Class exception
		class InvalidFormType : std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif //INC_42_CPP_MODULES_INTERN_H
