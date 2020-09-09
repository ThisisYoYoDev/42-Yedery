#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	int len = ft_strlen(av[1]);

	if (ac == 2)
	{
		while (len--)
			write(1, &av[1][len], 1);
	}
	write(1, "\n", 1);
	return (0);
}
