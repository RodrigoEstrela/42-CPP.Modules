//
// Created by rdas-nev on 3/29/23.
//

#include "../inc/PresidentialPardonForm.hpp"

// Orthodox Canonical Form =====================================================
PresidentialPardonForm::PresidentialPardonForm()
{
	this->setter("PresidentialPardonForm", false, 25, 5);
	this->target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->setter(other.getName(), other.getStatus(), other.getRequiredSigningGrade(), other.getRequiredExecGrade());
	this->target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm" << std::endl;
}
// =============================================================================

// Constructor with input ======================================================
PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
	this->setter("PresidentialPardonForm", false, 25, 5);
	this->target = target;
}
// =============================================================================

// Execute this form ===========================================================
void PresidentialPardonForm::executer() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
// =============================================================================