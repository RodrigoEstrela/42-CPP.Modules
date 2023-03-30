//
// Created by rdas-nev on 3/29/23.
//

#ifndef INC_42_CPP_MODULES_SHRUBBERRYCREATIONFORM_H
#define INC_42_CPP_MODULES_SHRUBBERRYCREATIONFORM_H

#include <fstream>
#include"../inc/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
	// Orthodox Canonical Form
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();
	// Constructor with input
		ShrubberyCreationForm(std::string target);
	// Execute this form
		void executer() const;
};

#endif //INC_42_CPP_MODULES_SHRUBBERRYCREATIONFORM_H
