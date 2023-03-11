//
// Created by rdas-nev on 3/10/23.
//

#include "../inc/ex01.hpp"

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main()
{
	PhoneBook phonebook;
	std::string input;
	while (1)
	{
		std::cout << "Enter command: "; std::cin >> input;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
