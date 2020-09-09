char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char swap;
	
	len = 0;
	while(str[len])
		len++;
	i = 0;
	while (i < --len)
	{
		swap = str[i];
		str[i] = str[len];
		str[len] = swap;
		i++;
	}
	return (str);
}

int main(void)
{
	char c[] = "SaluT";
	printf("%s\n", ft_strrev(c));
	return (0);
}
