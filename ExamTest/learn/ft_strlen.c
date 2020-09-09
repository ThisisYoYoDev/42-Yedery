int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(void)
{
	char a[] = "SALuT";
	printf("%d\n", ft_strlen(a));
	return (0);
}
