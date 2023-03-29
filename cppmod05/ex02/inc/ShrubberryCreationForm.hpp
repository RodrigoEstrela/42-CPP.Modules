//
// Created by rdas-nev on 3/29/23.
//

#ifndef INC_42_CPP_MODULES_SHRUBBERRYCREATIONFORM_H
#define INC_42_CPP_MODULES_SHRUBBERRYCREATIONFORM_H

#include"../inc/AForm.hpp"

class ShrubberryCreationForm : public AForm
{
	public:
	// Orthodox Canonical Form
		ShrubberryCreationForm();
		ShrubberryCreationForm(ShrubberryCreationForm const &other);
		ShrubberryCreationForm &operator=(ShrubberryCreationForm const &other);
		~ShrubberryCreationForm();
	// Constructor with input
		ShrubberryCreationForm(std::string target);
};


#endif //INC_42_CPP_MODULES_SHRUBBERRYCREATIONFORM_H
