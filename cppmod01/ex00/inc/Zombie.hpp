//
// Created by rdas-nev on 3/13/23.
//

#ifndef EX00_ZOMBIE_H
#define EX00_ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
		std::string name;
	public:
		Zombie(std::string name);
		void announce( void );
		Zombie* newZombie( std::string name );
		void randomChump( std::string name );
		~Zombie();
};

#endif //EX00_ZOMBIE_H
