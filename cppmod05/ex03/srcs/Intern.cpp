//
// Created by rdas-nev on 3/31/23.
//

#include "../inc/Intern.hpp"

// Orthodox Canonical Form =====================================================
Intern::Intern()
{
	this->nothingspecial = "nothingspecialaboutthisinter";
	std::cout << "Intern starts his shift." << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Intern copied." << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	this->nothingspecial = other.nothingspecial;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern offs himself." << std::endl;
}
// =============================================================================

// Make form ===================================================================
AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string possibleforms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int i = 0;
	for (; i < 3; i++)
		if (name == possibleforms[i])
			break;
	switch (i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
	}
	throw Intern::InvalidFormType();
}
// =============================================================================

// Class exception =============================================================
const char *Intern::InvalidFormType::what() const throw()
{
	return RED "Invalid type form" RESET;
}
// =============================================================================
