#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (*av[2] == '+')
			printf("%d\n", atoi(av[1]) + atoi(av[3]));
		if (*av[2] == '-')
			printf("%d\n", atoi(av[1]) - atoi(av[3]));
		if (*av[2] == '*')
			printf("%d\n", atoi(av[1]) * atoi(av[3]));
		if (*av[2] == '/')
			printf("%d\n", atoi(av[1]) / atoi(av[3]));
		if (*av[2] == '%')
			printf("%d\n", atoi(av[1]) % atoi(av[3]));
	}
	return (0);
}
