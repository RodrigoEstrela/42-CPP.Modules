//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/Bureaucrat.hpp"

// ORTHODOX CANONICAL FORM =====================================================
Bureaucrat::Bureaucrat() : name("Default")
{
	grade = 1;
	std::cout << "Default Constructor." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
	std::cout << "Copy Constructor." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	grade = other.getGrade();
	std::cout << "Copy Operator." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor." << std::endl;
}
// =============================================================================

// Constructor with input ======================================================
Bureaucrat::Bureaucrat(std::string const &nome, int grade) : name(nome)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "Constructor with input." << std::endl;
}
// =============================================================================

// Getters =====================================================================
std::string Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}
// =============================================================================

// Increment / Decrement =======================================================
void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	std::cout << "Grade incremented." << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	std::cout << "Grade decremented." << std::endl;
}
// =============================================================================

// Change AForm status ==========================================================
void Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() <<
		" because " << e.what() << std::endl;
	}
}
// =============================================================================

// Class Exceptions ============================================================
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}
// =============================================================================

// Execute Form ================================================================
void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't execute because: " << e.what() << std::endl;
	}
	catch (AForm::FormUnsignedException &e)
	{
		std::cout << this->getName() << " couldn't execute because: " << e.what() << std::endl;
	}
}
// =============================================================================

// Operator << overload ========================================================
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << "'s grade is: " << bureaucrat.getGrade() << ".";
	return out;
}
// =============================================================================
