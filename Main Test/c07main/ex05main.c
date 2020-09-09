
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int main(int argc, char **argv)
{
  char *str;
  char *ch;
  
  str = "YOEL IS HERE";
  ch = " ";
  ft_putstr(ft_split(str, ch)[0]);
  ft_putchar('\n');
  ft_putstr(ft_split(str, ch)[1]);
  ft_putchar('\n');
  ft_putstr(ft_split(str, ch)[2]);
  ft_putchar('\n');
  ft_putstr(ft_split(str, ch)[3]);
  ft_putchar('\n');
  ft_putstr(ft_split(str, ch)[4]);
  ft_putchar('\n');
  ft_putstr(ft_split(str, ch)[5]);
  ft_putchar('\n');

  return 0;
}
