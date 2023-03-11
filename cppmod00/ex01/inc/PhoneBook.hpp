//
// Created by rdas-nev on 3/10/23.
//

#ifndef EX01_PHONEBOOK_H
#define EX01_PHONEBOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
        Contact contacts[8];
		int contact_count;
        int index;
	public:
		PhoneBook();
		void add_contact();
		void search_contact();
};

#endif //EX01_PHONEBOOK_H
