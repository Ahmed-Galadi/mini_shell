/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:31:36 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/17 06:29:25 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_commands(char	*input)
{
	t_exec *output = tokenizer(input);
	t_exec *current = output;

	int		i = 1;

	while (current)
	{
		int		j = 0;
		if (current->command)
		{
			printf("\e[1;31m\n----------------%d----------------\e[0m", i++);
			printf("\n\e[1;32mcommand:\e[0m\t%s\n", current->command->command);
		}
		if (current->command->flag)
		{
			j = 0;
			printf("\e[1;32mflag:\e[0m\t\t");
			while (current->command->flag[j])
				printf("%s ", current->command->flag[j++]);
			printf("\n");
		}
		if (current->command->operator)
		{
			printf("\e[1;32moperator:\e[0m\n");
			while (current->command->operator != NULL)
			{
				printf("\t\e[1;34mtype:\e[0m\t\t%d\n", current->command->operator->type);
				printf("\t\e[1;34mfile:\e[0m\t%s\n", current->command->operator->file);
				printf("\t\e[1;34mdelimiter:\e[0m\t%s\n",current->command->operator->delimiter);
				printf("\n");
				current->command->operator = current->command->operator->next;
			}
		}
		if (current->command->options)
		{
			j = 0;
			printf("\e[1;32moptions:\e[0m\t");
			while (current->command->options[j])
				printf("%s ", current->command->options[j++]);
		}
		current = current->next;
	}
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char *input;
	while (1)
	{
		input = readline("\n$> ");
		if (ft_strcmp(input, "exit"))
			exit(0);
		print_commands(input);
	}
	return (0);
}