#include <stdio.h>
#include <stdlib.h>

int		pgcd(unsigned int nb1, unsigned int nb2)
{
	int i = nb1;
	while (i > 0)
	{	
		if (nb1 % i == 0 && nb2 % i == 0)
			return (i);
		i--;
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
	printf("\n");
	return (0);
}
