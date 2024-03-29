//
// Created by rdas-nev on 3/28/23.
//

#include "../inc/AForm.hpp"

// Orthodox Canonical AForm =====================================================
AForm::AForm() : name("formulary"), grade_sign(35), grade_exec(15)
{
	is_signed = false;
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
	is_signed = false;
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
		this->is_signed = true;
}
// =============================================================================

// Class Exceptions ============================================================
const char *AForm::GradeTooHighException::what() const throw()
{
	return RED"Grade Too High!"RESET;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return RED"Grade Too Low!"RESET;
}

const char *AForm::FormUnsignedException::what() const throw()
{
	return RED"The Form is UNSIGNED!"RESET;
}
// =============================================================================

// Execute the Form ============================================================
void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->is_signed)
		throw AForm::FormUnsignedException();
	else if (executor.getGrade() > this->getRequiredExecGrade())
		throw AForm::GradeTooLowException();
	else
		this->executer();
}
// =============================================================================

// Setter for the derived classes ==============================================
void AForm::setter(std::string const &nome, bool is_signed, int grade_sign, int grade_exec)
{
	this->name = nome;
	this->is_signed = is_signed;
	this->grade_sign = grade_sign;
	this->grade_exec = grade_exec;
}
// =============================================================================

// Operator << overload ========================================================
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "Name: " BLUE << f.getName() << std::endl <<RESET "Status: " YELLOW << f.getStatus() << std::endl <<
	RESET "Required grade for signing: " BLUE << f.getRequiredSigningGrade() << std::endl << RESET <<
	"Required grade for executing: " YELLOW << f.getRequiredExecGrade() << RESET;
	return out;
}
// =============================================================================
