int		ft_atoi(const char *str)
{
	int y;
	int z;
	int nb;

	y = 0;
	z = 0;
	nb = 0;
	while (str[y] == ' ' || (str[y] >= 9 && str[y] <= 13))
		y++;
	if (str[y] == '-')
		z = 1;
	if (str[y] == '+' || str[y] == '-')
		y++;
	while (str[y] && (str[y] >= '0' && str[y] <= '9'))
	{
		nb = nb * 10 + (int)str[y] - 48;
		y++;
	}
	return ((z == 1) ? -nb : nb); 
}

int		main(void)
{
	char a[] = "-5234AAAgreghrsth";// -5234
	printf("%d\n",ft_atoi(a));//
	printf("%d\n",atoi(a));//

}
