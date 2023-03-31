//
// Created by rdas-nev on 3/29/23.
//

#include "../inc/ShrubberyCreationForm.hpp"

// Orthodox Canonical Form =====================================================
ShrubberyCreationForm::ShrubberyCreationForm()
{
	this->setter("ShrubberyCreationForm", false, 145, 137);
	this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->setter(other.getName(), other.getStatus(), other.getRequiredSigningGrade(), other.getRequiredExecGrade());
	this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShruberryCreationForm destroyed." << std::endl;
}
// =============================================================================

// Constructor with input ======================================================
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
	this->setter("ShrubberyCreationForm", false, 145, 137);
	this->target = target;
}
// =============================================================================

// Execute this form ===========================================================
void ShrubberyCreationForm::executer() const
{
	std::ofstream ofs; ofs.open((this->target + "_shruberry").c_str());
	ofs << "               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	ofs.close();
}
// =============================================================================
