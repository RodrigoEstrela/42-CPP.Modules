//
// Created by rdas-nev on 3/10/23.
//

#ifndef EX01_CONTACT_H
#define EX01_CONTACT_H

#include <string>
#include <iostream>
#include <string>

class Contact
{
	    std::string first_name,
        last_name,
        nickname,
        phone_number,
        darkest_secret;
    public:
	    Contact();
	    void get_info();
	    void set_info();
        void show_info_line();
};

#endif //EX01_CONTACT_H
