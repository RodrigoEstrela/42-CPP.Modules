//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/Form.hpp"

// Orthodox Canonical Form =====================================================
Form::Form() : name("formulary"), grade_sign(35), grade_exec(15)
{
	is_signed = 0;
	std::cout << "Form printed." << std::endl;
}

Form::Form(Form const &other) :
grade_sign(other.getRequiredSigningGrade()), grade_exec(other.getRequiredExecGrade())
{
	*this = other;
	std::cout << "Form copied." << std::endl;
}

Form &Form::operator=(const Form &other)
{
	this->is_signed = other.is_signed;
	std::cout << "Copy operator." << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Formulary shredded." << std::endl;
}
// =============================================================================

// Getters =====================================================================
std::string Form::getName() const
{
	return this->name;
}

bool Form::getStatus() const
{
	return this->is_signed;
}

int Form::getRequiredSigningGrade() const
{
	return this->grade_sign;
}

int Form::getRequiredExecGrade() const
{
	return this->grade_exec;
}
// =============================================================================

// Change Status Method ========================================================
void Form::beSigned(Bureaucrat const &b)
{
	try
	{
		b.signForm(this->getRequiredSigningGrade());
		this->is_signed = 1;
		std::cout << b.getName() << " signed " << this->getName();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		throw Form::GradeTooLowException();
	}
}
// =============================================================================

// Class Exceptions ============================================================
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}
// =============================================================================

// Operator << overload ========================================================
std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form: " << f.getName() << " attributes are:\n" <<
	"Status: " << f.getStatus() <<
	"Required grade for signing: " << f.getRequiredSigningGrade() <<
	"Required grade for executing: " << f.getRequiredExecGrade() << std::endl;
	return out;
}
// =============================================================================
