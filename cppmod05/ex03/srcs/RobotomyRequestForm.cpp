//
// Created by rdas-nev on 3/29/23.
//

#include "../inc/RobotomyRequestForm.hpp"

// Orthodox Canonical Form =====================================================
RobotomyRequestForm::RobotomyRequestForm()
{
	this->setter("RobotomyRequestForm", false, 72, 45);
	this->target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->setter(other.getName(), other.getStatus(), other.getRequiredSigningGrade(), other.getRequiredExecGrade());
	this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed." << std::endl;
}
// =============================================================================

// Constructor with input ======================================================
RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
	this->setter("RobotomyRequestForm", false, 72, 45);
	this->target = target;
}
// =============================================================================

// Execute this form ===========================================================
void RobotomyRequestForm::executer() const
{
	srand(time(NULL));
	int i = rand() % 2;
	if (i)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomization failed." << std::endl;
}
// =============================================================================