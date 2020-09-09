#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	char letter;

	if (ac == 2)
	{
		while (av[1][i])
		{
			letter = av[1][i];
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				letter = 'Z' - av[1][i] + 'A';
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				letter = 'z' - av[1][i] + 'a';
			write(1, &letter, 1);
			i = i + 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
