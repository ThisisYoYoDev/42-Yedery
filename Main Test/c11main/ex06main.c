#include <stdio.h>
#include <stdlib.h>
int		main(void)
{
	char	*strs[100];
	int		i;

	printf("ex06/FT_SORT_STRING_TAB\n-------------------------------\n");
	strs[0] = "ab";
	strs[1] = "13 ";
	strs[2] = "xff";
	strs[3] = "   .adf/";
	strs[4] = "			 fefkwtoto!@#$%^&123654";
	strs[5] = "			-9865toto!@#$%^&123654";
	strs[6] = "		3455777##toto!@#$%^&123654";
	strs[7] = "	\vt\r\etoto!@#$%^&123654";
	strs[8] = "		234%^&*()toto!@#$%^&123654";
	strs[9] = "98-++-+++++-+toto!@#$%^&123654";
	strs[10] = "					qwertyuitoto!@#$%^&123654";

	ft_sort_string_tab(strs);
	i = -1;
	while (strs[++i])
		printf("%s\n", strs[i]);
}
