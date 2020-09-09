#include <stdio.h>

int	ft_absval(int nb)
{
	if (nb < 0)
		return -(nb);
	else 
		return (nb);
}

int		main(void)
{
	int array[] = {1, -3, 4, -4, 5, 6, -1};

	int	*res = ft_map(array, 7, &ft_absval);
	int i = 0;

	while (i < 7)
	{
		printf("%d\t", res[i]);
		i++;
	}
	return (0);
}
