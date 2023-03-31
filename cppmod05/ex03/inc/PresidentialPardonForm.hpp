//
// Created by rdas-nev on 3/29/23.
//

#ifndef INC_42_CPP_MODULES_PRESIDENTIALPARDONFORM_H
#define INC_42_CPP_MODULES_PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
	// Orthodox Canonical Form
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
	// Constructor with input
		PresidentialPardonForm(std::string target);
	// Execute this form
		void executer() const;
};


#endif //INC_42_CPP_MODULES_PRESIDENTIALPARDONFORM_H
