//
// Created by rdas-nev on 4/5/23.
//

#include "../inc/Array.hpp"

int main()
{
    // Default constructor -----------------------------------------------------
    Array<int> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;
    // Constructor with an unsigned int parameter ------------------------------
    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;
    // Copy constructor --------------------------------------------------------
    Array<int> arr3(arr2);
    std::cout << "arr3 size: " << arr3.size() << std::endl;
    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;
    // Assignment operator overload --------------------------------------------
    Array<int> arr4;
    arr4 = arr3;
    std::cout << "arr4 size: " << arr4.size() << std::endl;
    for (unsigned int i = 0; i < arr4.size(); i++)
        std::cout << arr4[i] << " ";
    std::cout << std::endl;
    // Index operator overload -------------------------------------------------
    try
    {
        arr2[-5] = 1;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
    for (unsigned int i = 0; i < arr2.size(); i++)
    {
        arr2[i] = i;
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
