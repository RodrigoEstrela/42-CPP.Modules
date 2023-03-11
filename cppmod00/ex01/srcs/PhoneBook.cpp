//
// Created by rdas-nev on 3/10/23.
//

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_count = 0;
    index = 0;
	for (int i = 0; i < 8; i++)
		contacts[i] = Contact();
}

void PhoneBook::add_contact()
{
    if (contact_count < 8)
    {
        contact_count++;
    }
	if (index < 8)
	{
		contacts[index].set_info();
        index++;
	}
	else
	{
		index = 0;
		contacts[index].set_info();
	}
}

void PhoneBook::search_contact()
{
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
        contacts[i].show_info_line();
    }
    int idx;
    std::cout << "Enter index: "; std::cin >> idx;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (idx >= 0 && idx < contact_count)
        contacts[idx].get_info();
    else
        std::cout << "Invalid index" << std::endl;
    return;
}
