//
// Created by rdas-nev on 14-03-2023.
//

#include "../inc/replace_to_file.h"

void replace_to_file(std::string& line, const std::string& s1, const std::string& s2)
{
   std::string substring = line.substr(line.find(s1), s1.length());
   line.insert(line.find(s1), s2);
   line.erase(line.find(s1), s1.length());
}
