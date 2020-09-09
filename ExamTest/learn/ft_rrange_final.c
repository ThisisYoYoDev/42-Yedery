#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int *r;
	int len;

	len = (end >= start) ? end - start + 1 : start - end + 1;
	if (!(r = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (len--)
		r[len] = (end >= start) ? start++ : start--;
	return (r);
}

int main(void)
{
	int i;
	int *prt;

	i = 0;
	prt = ft_rrange(1, 3);
	while(i <= 2)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");

	i = 0;
	prt = ft_rrange(-1, 2);
	while(i <= 3)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");

	i = 0;
	prt = ft_rrange(0, 0);
	while(i <= 0)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");

	i = 0;
	prt = ft_rrange(0, -3);
	while(i <= 3)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");

	return (0);
}
