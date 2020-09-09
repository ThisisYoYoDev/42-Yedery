#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int i;
	char *str;
	
	str = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	char s[] = "salut";
	printf ("result : %s", ft_strdup(s));
	return (0);
}
