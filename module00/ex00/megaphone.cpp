#include <iostream>

void to_upper(char **argv)
{
	for (int i = 0; argv[++i];)
	{
		for (int j = -1; argv[i][++j];)
		{
			if (std::isalpha(argv[i][j]))
				argv[i][j] = std::toupper(argv[i][j]);
		}
		std::cout << argv[i];
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		to_upper(argv);
	std::cout << std::endl;
	return (0);
}