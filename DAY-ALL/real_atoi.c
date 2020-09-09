int	ft_atoi(char *str)
{
	int y;
	int z;
	int nb;

	y = 0;
	z = 0;
	nb = 0;
	while ((str[y] == ' ') || (str[y] == '\t')
		|| (str[y] == '\n') || (str[y] == '\v')
		|| (str[y] == '\r') || (str[y] == '\f'))
		y++;
	if (str[y] == '-')
		z = 1;
	if (str[y] == '+' || str[y] == '-')
		y++;
	while (str[y] && (str[y] >= '0') && (str[y] <= '9'))
	{
		nb = nb * 10 + (int)str[y] - 48;
		y++;
	}
	if (z == 1)
		return (-nb);
	else
		return (nb);
}
