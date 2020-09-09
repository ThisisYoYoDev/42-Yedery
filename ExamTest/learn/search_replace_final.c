#include <unistd.h>

int		main(int ac, char **av)
{
	int y;

	if (ac != 4)
		write(1, "\n", 1);
	if (av[2][1] || av[3][1])
		write(1, "\n", 1);
	y = 0;
	while (av[1][y])
	{
		if (av[1][y] == *av[2])
			av[1][y] = *av[3];
		write(1, &av[1][y], 1);
		y++;
	}
	write (1, "\n", 1);
	return (0);
}
