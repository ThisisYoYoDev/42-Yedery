int		ft_blank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		base_valid(char c, int base)
{
	char base1[17] = "0123456789abcdef";
	char base2[17] = "0123456789ABCDEF";

	while (base--)
		if (base1[base] ==c || base2[base] == c)
			return (1);
	return (0);
}

int value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return(0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int res;
	int sign;

	res = 0;
	while (ft_blank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '+' || *str == '-') ? ++str : 0;
	while (base_valid(*str, str_base))
		res = res * str_base + value(*str++);
	return (res * sign);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("011", atoi("2")));
	printf("%d\n", ft_atoi_base("16", atoi("8")));
	printf("%d\n", ft_atoi_base("123", atoi("10")));
	printf("%d\n", ft_atoi_base("FF", atoi("16")));
}
