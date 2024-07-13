/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:31:36 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/13 04:56:33 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_commands(char	*input)
{
	t_exec *output = tokenizer(input);
	t_exec *current = output;
	int		i = 1;
	//int		j = 0;

	while (current)
	{
		printf("\n----------------%d----------------", i++);
		printf("\ncommand:\t%s\n", current->command->command);
		printf("flag:\t\t%s\n", current->command->flag[0]);
		if (current->command->operator)
		{
			printf("operator:\n\ttype:\t\t%d\n", current->command->operator->type);
			printf("\tout file:\t%s\n", current->command->operator->out_file);
			printf("\tdelimiter:\t%s\n",current->command->operator->delimiter);
		}
		printf("options:\t");
		printf("%s ", output->command->options[0]);
		current = current->next;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		print_commands(argv[1]);
	else
		printf("error\n");
	return (0);
}