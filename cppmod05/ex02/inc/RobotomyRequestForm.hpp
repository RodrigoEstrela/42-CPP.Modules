//
// Created by rdas-nev on 3/29/23.
//

#ifndef INC_42_CPP_MODULES_ROBOTOMYREQUESTFORM_H
#define INC_42_CPP_MODULES_ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
	// Orthodox Canonical Form
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		~RobotomyRequestForm();
	// Constructor with input
		RobotomyRequestForm(std::string target);
	// Execute this form
		void executer() const;
};

#endif //INC_42_CPP_MODULES_ROBOTOMYREQUESTFORM_H
