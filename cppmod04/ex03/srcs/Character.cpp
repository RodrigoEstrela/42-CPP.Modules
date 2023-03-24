//
// Created by rdas-nev on 3/23/23.
//

#include "../inc/Character.hpp"

Character::Character(std::string const &name) : name(name)
{
	std::cout << "Character " << name << " created!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

// deep copy
Character::Character(Character const &other) : name(other.name), inventory()
{
	*inventory = NULL;
	*this = other;
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	std::cout << "Character " << name << " copied!" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	std::cout << "Character " << name << " destroyed!" << std::endl;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	if (inventory[idx])
	{
		inventory[idx] = 0;
	}
}


void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return;
	if (inventory[idx])
		inventory[idx]->use(target);
}
