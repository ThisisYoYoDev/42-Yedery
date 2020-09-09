int main()
{
	char* strs[] = {"Salut", "ca va","toto"};
	int size = 3;
	char *sep = " : ";
	printf("%s",ft_strjoin(size, strs, sep));
}
