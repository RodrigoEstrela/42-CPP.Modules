//
// Created by rdas-nev on 14-03-2023.
//

#ifndef EX05_HARL_H
#define EX05_HARL_H

#include <iostream>

class Harl
{
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        Harl();
        void complain(std::string level);
        ~Harl();
};


#endif //EX05_HARL_H
