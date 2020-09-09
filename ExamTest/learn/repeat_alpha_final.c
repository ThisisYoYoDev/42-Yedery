#include <unistd.h>

int		repeat_letter(char c)
{
	int repeat;

	repeat = 0;
	if (c >= 'A' && c <= 'Z')
		repeat = c - 'A' + 1;
	if (c >= 'a' && c <= 'z')
		repeat = c -'a' + 1;
	else
		repeat = 1;
	return (repeat);
}

int		main(int ac, char **av)
{
	int repeat;

	repeat = 0;
	if (ac == 2)
	{
		while (*av[1])
		{
			repeat = repeat_letter(*av[1]);
			while (repeat--)
				write(1, av[1], 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
