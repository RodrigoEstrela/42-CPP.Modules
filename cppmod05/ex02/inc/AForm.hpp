//
// Created by rdas-nev on 3/28/23.
//

#ifndef INC_42_CPP_MODULES_FORM_H
#define INC_42_CPP_MODULES_FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const name;
		bool is_signed;
		int const grade_sign;
		int const grade_exec;
	public:
	// Orthodox Canonical Form
		AForm();
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		~AForm();
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
		virtual void executer() const;
};

// Operator << overload
std::ostream &operator<<(std::ostream &out, const AForm &f);
#endif //INC_42_CPP_MODULES_FORM_H
