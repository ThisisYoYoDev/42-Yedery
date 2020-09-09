int	ft_strlen(char *str)
{
	int y;

	y = 0;
	while(str[y])
		y++;
	return (y);
}

char *ft_strdup(char *src)
{
	char	*str;
	int		y;

	str = malloc(sizeof(char)* ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	y = 0;
	while (src[y])
	{
		str[y] = src[y];
		y++;
	}
	str[y] = '\0';
	return (str);
}

int	main(void)
{
	char s[] = "salut";
	printf ("result : %s", ft_strdup(s));
	return (0);
}

