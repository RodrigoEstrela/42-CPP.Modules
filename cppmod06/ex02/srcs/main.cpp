//
// Created by rdas-nev on 4/5/23.
//

#include "../inc/Classes.hpp"

int main()
{
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}
