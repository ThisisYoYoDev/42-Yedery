#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'Y') || (*str >= 'a' && *str <= 'y'))
			ft_putchar(*str + 1);
		else if (*str == 'Z' || *str == 'z')
			ft_putchar(*str - 25);
		else
			ft_putchar(*str);
		++str;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}
