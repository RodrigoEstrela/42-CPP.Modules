//
// Created by rdas-nev on 3/21/23.
//

#include"../inc/Animal.h"
#include"../inc/Cat.h"
#include"../inc/Dog.h"

int main()
{
//    Animal test;

    Animal *a = new Dog();
    a->makeSound();
    delete a;
    std::cout << std::endl;

    Animal *b = new Cat();
    b->makeSound();
    delete b;
    std::cout << std::endl;

    return 0;
}
