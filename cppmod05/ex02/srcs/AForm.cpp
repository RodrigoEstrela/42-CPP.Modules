//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/AForm.hpp"

// Orthodox Canonical AForm =====================================================
AForm::AForm() : name("formulary"), grade_sign(35), grade_exec(15)
{
	is_signed = 0;
	std::cout << "AForm printed." << std::endl;
}

AForm::AForm(AForm const &other) :
grade_sign(other.getRequiredSigningGrade()), grade_exec(other.getRequiredExecGrade())
{
	*this = other;
	std::cout << "AForm copied." << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	this->is_signed = other.is_signed;
	std::cout << "Copy operator." << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Formulary shredded." << std::endl;
}
// =============================================================================

// Constructor with input ======================================================
AForm::AForm(std::string nome, int gsign, int gexec) : name(nome),
													   grade_sign(gsign), grade_exec(gexec)
{
	if (gsign < 1 || gexec < 1)
		throw AForm::GradeTooHighException();
	else if (gsign > 150 || gexec > 150)
		throw AForm::GradeTooLowException();
	is_signed = 0;
}
// =============================================================================

// Getters =====================================================================
std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getStatus() const
{
	return this->is_signed;
}

int AForm::getRequiredSigningGrade() const
{
	return this->grade_sign;
}

int AForm::getRequiredExecGrade() const
{
	return this->grade_exec;
}
// =============================================================================

// Change Status Method ========================================================
void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->getRequiredSigningGrade())
		throw AForm::GradeTooLowException();
	else
		this->is_signed = 1;
}
// =============================================================================

// Class Exceptions ============================================================
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

const char *AForm::FormUnsignedException::what() const throw()
{
	return "The Form is UNSIGNED!";
}
// =============================================================================

// Execute the Form ============================================================
void AForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == 0)
		throw AForm::FormUnsignedException();
	else if (executor.getGrade() > this->getRequiredExecGrade())
		throw AForm::GradeTooLowException();
	else
		this->executer();
}


// =============================================================================

// Operator << overload ========================================================
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "Name: " << f.getName() << std::endl << "Status: " << f.getStatus() << std::endl <<
	"Required grade for signing: " << f.getRequiredSigningGrade() << std::endl <<
	"Required grade for executing: " << f.getRequiredExecGrade();
	return out;
}
// =============================================================================
