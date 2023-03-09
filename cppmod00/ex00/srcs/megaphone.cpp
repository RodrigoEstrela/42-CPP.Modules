#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)toupper(argv[i][j]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
