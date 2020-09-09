
int ft_islower(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] < 'a' || str[i] > 'z')
      return (0);
    i++;
  }
  return (1);
}

#include <stdio.h>

int main(void)
{
  char *arr[3][6] = { "oDne", "tDwo", "D" };

  printf("ft_any: %d", ft_any(arr, ft_islower));
  return 0;
}
