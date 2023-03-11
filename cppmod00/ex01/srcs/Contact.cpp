//
// Created by rdas-nev on 3/10/23.
//

#include "../inc/Contact.hpp"
#include "../inc/ex01.hpp"

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

void Contact::set_info()
{
	std::cout << "Enter first name: "; std::cin >> first_name;
	std::cout << "Enter last name: "; std::cin >> last_name;
	std::cout << "Enter nickname: "; std::cin >> nickname;
	std::string n = "0";
	while (1)
	{
		std::cout << "Enter phone number: "; std::cin >> n;
		if (is_number(n))
			break;
		else
			std::cout << "Phone number must be a number" << std::endl;
	}
	phone_number = n;
	std::cout << "Enter darkest secret: "; std::cin >> darkest_secret;
}

void Contact::get_info()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

void Contact::show_info_line()
{
    std::string tmp;
    if (first_name.length() > 10)
    {
        tmp = first_name.substr(0, 9);
        tmp += ".";
        std::cout << std::setw(10) << tmp << "|";
    }
    else
        std::cout << std::setw(10) << first_name << "|";
    if (last_name.length() > 10)
    {
        tmp = last_name.substr(0, 9);
        tmp += ".";
        std::cout << std::setw(10) << tmp << "|";
    }
    else
        std::cout << std::setw(10) << last_name << "|";
    if (nickname.length() > 10)
    {
        tmp = nickname.substr(0, 9);
        tmp += ".";
        std::cout << std::setw(10) << tmp << std::endl;
    }
    else
        std::cout << std::setw(10) << last_name << std::endl;
}
