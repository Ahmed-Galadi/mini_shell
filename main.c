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

// void	check_pipe_in_quote(char *str)
// {
// 	char	*tmp;
// 	int		i;

// 	if ((quotes_count(str) % 2) != 0)
// 		error();
// 	tmp = str;
// 	i = 0;
// 	while (tmp[i] && tmp[i] != '\"')
// 		i++;
// 	while (tmp[i] && tmp[i] == '\"')
// 		i++;
// 	while (tmp[i])
// 	{
// 		if (tmp[i] == '|')
// 		{
// 			tmp[i] = (char)-1;
// 			tmp = tmp + i + 1;
// 			i = 0;
// 		}
// 		if (tmp[i] == '\"')
// 			break;
// 		i++;
// 	}
// }
void	skip_quotes(char *str ,int *i)
{
	while (str[*i] == '\"')
		*i += 1;
}
int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while(str[count])
		count++;
	return (count);
}

char	*trim_quotes(char *str)
{
	char	*output;
	int		i;
	int		j;

	if ((quotes_count(str) % 2) != 0)
		error();
	output = malloc(ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			output[j] = '\"';
			skip_quotes(str, &i);
			j++;
		}
		else
			output[j++] = str[i++];
	}
	output[j] = '\0';
	return (output);
}


char	*format(char *str)
{
	char	*output;
	int		in_quote;
	int		i;

	// remove uneeded quotes
	output = trim_quotes(str);
	// check for pipes and change them to (char)-1
	in_quote = 0;
	i = 0;
	while (output[i])
	{
		if (output[i] == '\"' && !in_quote)
			in_quote = 1;
		else if (output[i] == '\"' && in_quote)
			in_quote = 0;
		if (in_quote && output[i] == '|')
			output[i] = (char)-1;
		i++;
	}
	return (output);
}



int main(int argc, char *argv[])
{
	char str[] = "cat -e |  \"\"\"mel' | ody\"\"\" \"\"\"|\"\"\" | ";
	printf("%s\n", str);
	printf("%s\n", format(str));

	return (0);
}