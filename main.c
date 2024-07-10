#include <stdio.h>
#include "main.h"

void	error()
{
	exit(EXIT_FAILURE);
}

int		quotes_count(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			count++;
		i++;
	}
	return (count);

}

void	check_pipe_in_quote(char *str)
{
	char	*tmp;
	int		i;

	if ((quotes_count(str) % 2) != 0)
		error();
	tmp = str;
	i = 0;
	while (tmp[i] && tmp[i] != '\"')
		i++;
	while (tmp[i] && tmp[i] == '\"')
		i++;
	while (tmp[i])
	{
		if (tmp[i] == '|')
		{
			tmp[i] = (char)-1;
			tmp = tmp + i + 1;
			i = 0;
		}
		if (tmp[i] == '\"')
			break;
		i++;
	}
}

int main(int argc, char *argv[])
{
	char str[] = "cat -e |  \"\"\"mel' | ody\"\"\" | ";
	printf("%s\n", str);
	check_pipe_in_quote(str);
	printf("%s\n", str);

	return (0);
}