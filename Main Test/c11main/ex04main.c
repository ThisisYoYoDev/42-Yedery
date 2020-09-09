
#include <stdio.h>

int		ft_comp(int i, int j)
{
	return (i-j);
}

int		main(void)
{
	int		sorted_tab[4] = {14, 27, 42, 53};
	int		nonsorted_tab[4] = {14, 27, 42, 12};
	int		sorted = ft_is_sort(sorted_tab, 4, &ft_comp);
	int		nonsorted = ft_is_sort(nonsorted_tab, 4, &ft_comp);
	printf("%i, %i", sorted, nonsorted);
	return 0;
}

