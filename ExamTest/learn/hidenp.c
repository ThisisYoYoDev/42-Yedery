#include <unistd.h>

void	hidenp(char *str1, char *str2)
{
	while (*str2)
		if (*str1 == *str2++)
			str1++;
	if (*str1 == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
