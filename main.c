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

char	*check_pipe_in_quote(char *str)
{
	if ((quotes_count(str) % 2) != 0)
		error();
	
}

int main(int argc, char *argv[])
{
	
	return (0);
}