/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:31:36 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/12 07:08:25 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_commands(char	*input)
{
	t_exec *output = tokenizer(input);
	t_exec *current = output;

	while (current)
	{
		printf("\ncommand:\t%s\nflag:\t%s\noperator:\n\ttype:\t%d\n\tout file:\t%s\n\tdelimiter:\t%s\n",
			current->command->command, current->command->flag,
			current->command->operator->type, current->command->operator->out_file,
			current->command->operator->delimiter);
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