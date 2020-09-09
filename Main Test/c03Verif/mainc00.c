#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(void)
{
	char str[] = "A";
	char to_find[] = "B"; 
	printf("%d", ft_strcmp(str, to_find));
	return(0);
}
