int	ft_atoi(const char *str)
{
	int y;
	int z;
	int nb;

	y = 0;
	z = 0;
	nb = 0;
	while (str[y] == ' ' || ((str[y] >= 9) && (str[y] <= 13)))
		y++;
	if (str[y] == '-')
		z = 1;
	if (str[y] == '+' || str[y] == '-')
		y++;
	while (str[y] && (str[y] >= '0') && (str[y] <= '9'))
	{
		nb = nb * 10 + (int)str[y] - '0';
		y++;
	}
	if (z == 1)
		return (-nb);
	else
		return (nb);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", atoi("-2147483648"));
	return (0);
}
