/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:51:35 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/12 07:05:45 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

t_exec	*new_exec(t_command *command, t_exec *prev)
{
	t_exec	*output;

	output = (t_exec *)malloc(sizeof(t_exec));
	if (!output)
		return (NULL);
	output->prev = prev;
	output->command = command;
	output->next = NULL;
	return (output);
}

t_exec	*tokenizer(char *input)
{
	t_exec	*output;
	t_exec	*current;
	char	*format_input;
	char	**splited_input;
	int		i;

	format_input = format(input);
	splited_input = ft_split(format_input, '|');
	i = 0;
	output = new_exec(new_command(splited_input[i++]), NULL);
	current = output;
	while (splited_input[i])
	{
		current->next = new_exec(new_command(splited_input[i++]), current);
		current = current->next;
	}
	return (output);
}