//
// Created by rdas-nev on 3/10/23.
//

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_count = 0;
	for (int i = 0; i < 8; i++)
		contacts[i] = Contact();
}

void PhoneBook::add_contact()
{
	if (contact_count < 8)
	{
		contacts[contact_count].set_info();
		contact_count++;
	}
	else
	{
		contact_count = 0;
		contacts[contact_count].set_info();
		contact_count++;
	}
}

void PhoneBook::search_contact()
{
	std::string input;
	int index = 0;

	if (contact_count == 0)
	{
		std::cout << "No contacts to search" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		contacts[i].get_info();
	}
	std::cout << "Enter index: "; std::cin >> input;
	if ((index - 48) >= 0 && (index - 48) < contact_count)
		contacts[index - 48].get_info();
	else
		std::cout << "Invalid index" << std::endl;
}