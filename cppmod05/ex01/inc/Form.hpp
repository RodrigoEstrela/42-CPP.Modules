//
// Created by rdas-nev on 3/28/23.
//

#ifndef INC_42_CPP_MODULES_FORM_H
#define INC_42_CPP_MODULES_FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const name;
		bool is_signed;
		int const grade_sign;
		int const grade_exec;
	public:
	// Orthodox Canonical Form
		Form();
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();
	// Constructor with input
		Form(std::string nome, int gsign, int gexec);
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
};

// Operator << overload
std::ostream &operator<<(std::ostream &out, const Form &f);
#endif //INC_42_CPP_MODULES_FORM_H
