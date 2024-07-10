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

void	skip_quotes(char *str ,int *i)
{
	while (str[*i] == '\"')
		*i += 1;
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
 void	mask_pipes(char *str)
 {
	int		in_quote;
	int		i;

	in_quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && !in_quote)
			in_quote = 1;
		else if (str[i] == '\"' && in_quote)
			in_quote = 0;
		if (in_quote && str[i] == '|')
			str[i] = (char)-1;
		i++;
	}
 }




char	*format(char *str)
{
	char	*output;

	// remove uneeded quotes
	output = trim_quotes(str);
	// check for pipes and change them to (char)-1
	mask_pipes(output);
	// fotmat the input by adding spaces 
	output = add_spaces(output);
	return (output);
}



int main(int argc, char *argv[])
{
	char str[] = "cat -e |\"\"\"mel'|ody\"\"\" \"\"\"|\"\"\"|cat";
	printf("%s\n", str);
	printf("%s\n", format(str));

	return (0);
}