//
// Created by rdas-nev on 3/28/23.
//

#ifndef INC_42_CPP_MODULES_FORM_H
#define INC_42_CPP_MODULES_FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

class Bureaucrat;

class AForm
{
	private:
		std::string name;
		bool is_signed;
		int grade_sign;
		int grade_exec;
		std::string target;
	public:
	// Orthodox Canonical Form
		AForm();
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		virtual ~AForm();
	// Constructor with input
		AForm(std::string nome, int gsign, int gexec);
	// Getters
		std::string getName() const;
		bool getStatus() const;
		int	getRequiredSigningGrade() const;
		int getRequiredExecGrade() const;
	// Change Status Method
		void beSigned(Bureaucrat const &b);
	// Class Exceptions
		class GradeTooHighException : std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormUnsignedException : std::exception
		{
			public:
				const char *what() const throw();
		};
	// Execute the Form
		void execute(Bureaucrat const &executor) const;
	protected:
		virtual void executer() const = 0;
	// Setter for the derived classes
		virtual void setter(std::string const &nome, bool is_signed, int grade_sign, int grade_exec);
};

// Operator << overload
std::ostream &operator<<(std::ostream &out, const AForm &f);
#endif //INC_42_CPP_MODULES_FORM_H
