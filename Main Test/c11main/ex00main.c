#include <stdio.h>

void ft_putnbr(int n)
{
	printf("%d,", n);
}

int main()
{
 	int test1[] = {1,2,3,4,5};
 	int test2[] = {-25,0,20,45};
 	int test3[] = {5};

	ft_foreach(test1, 5, ft_putnbr);
	printf("\n");
 	ft_foreach(test2, 3, ft_putnbr);
 	printf("\n");
 	ft_foreach(test3, 0, ft_putnbr);
 	printf("\n");
}
