#include <iostream>
#include <string>
#include <cctype>

/**
 * @brief Convert the passed arguments to uppercase and display them
 * 
 * @param ac 
 * @param av 
 * @return int 0 if nothing went wrong
 */
int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
		for (int j = 0; av[i][j] != '\0'; ++j)
		{
			std::cout << (char)std::toupper(av[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}