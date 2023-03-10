//
// Created by rdas-nev on 3/10/23.
//

#include <string>
#include <iostream>
#include <ctype.h>

class Contact
{
		std::string first_name,
					last_name,
					nickname,
					phone_number,
					darkest_secret;
	public:
		Contact();
		std::string get_name() const;
		std::string get_phone() const;
		void get_info();
		void set_info();
};

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

int main()
{
	Contact contact;
	std::string input;
	while (1)
	{
		std::cout << "Enter command: "; std::cin >> input;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			contact.set_info();
		else if (input == "SEARCH")
			contact.get_info();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
