#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	int i = 1;
	std::string str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (ac == 1)
		std::cout << str;
	while (i < ac)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)toupper(av[i][j]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
