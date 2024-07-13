/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:31:36 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/13 05:23:23 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <readline/readline.h>

void	print_commands(char	*input)
{
	t_exec *output = tokenizer(input);
	t_exec *current = output;
	int		i = 1;
	int		j = 0;

	while (current)
	{
		printf("\n----------------%d----------------", i++);
		printf("\ncommand:\t%s\n", current->command->command);
		if (current->command->flag)
		{
			printf("flag:\t\t");
			while (current->command->flag[j])
				printf("%s ", current->command->flag[j++]);
			printf("\n");
		}
		if (current->command->operator)
		{
			printf("operator:\n\ttype:\t\t%d\n", current->command->operator->type);
			printf("\tout file:\t%s\n", current->command->operator->out_file);
			printf("\tdelimiter:\t%s\n",current->command->operator->delimiter);
		}
		printf("options:\t");
		j = 0;
		while (output->command->options[j])
			printf("%s ", output->command->options[j++]);
		current = current->next;
	}
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	while (1)
		print_commands(readline("\n>"));
	return (0);
}