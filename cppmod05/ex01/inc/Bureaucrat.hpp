//
// Created by rdas-nev on 3/28/23.
//

#ifndef INC_42_CPP_MODULES_BUREAUCRAT_H
#define INC_42_CPP_MODULES_BUREAUCRAT_H

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
	//  Orthodox Canonical Form
		Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();
	// Constructor with input
		Bureaucrat(std::string const &nome, int grade);
	// Getters
		std::string getName() const;
		int getGrade() const;
	// Increment / Decrement
		void incrementGrade();
		void decrementGrade();
	// Change Form status
		void signForm(Form &f) const;
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
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif //INC_42_CPP_MODULES_BUREAUCRAT_H
