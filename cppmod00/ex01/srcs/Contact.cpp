//
// Created by rdas-nev on 3/10/23.
//

#include "../inc/Contact.hpp"
#include "../inc/ex01.hpp"

Contact::Contact()
{
	this->first_name = "0";
	this->last_name = "0";
	this->nickname = "0";
	this->phone_number = "0";
	this->darkest_secret = "0";
}

// check if string is a number
bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
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
