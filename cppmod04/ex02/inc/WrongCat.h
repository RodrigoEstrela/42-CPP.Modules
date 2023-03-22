//
// Created by rdas-nev on 3/21/23.
//

#ifndef INC_42_CPP_MODULES_WRONGCAT_H
#define INC_42_CPP_MODULES_WRONGCAT_H

#include"WrongAnimal.h"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const &other);
		WrongCat &operator=(WrongCat const &other);
		~WrongCat();
};


#endif //INC_42_CPP_MODULES_WRONGCAT_H
