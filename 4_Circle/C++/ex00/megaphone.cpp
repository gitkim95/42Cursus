#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		int j = 0;
		while (argv[i][j])
		{
			if (97 <= argv[i][j] && argv[i][j] <= 122)
				argv[i][j] -= 32;
			j++;
		}
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return (0);
}
