/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:51:35 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/11 06:01:41 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int		command_count(char **commands)
{
	int		count;

	count = 0;
	while (commands[count])
		count++;
	return (count);
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
	output = new_exec(new_command(splited_input[i++]), NULL);
	current = output;
	while (splited_input[i])
	{
		current->next = new_exec(new_command(splited_input[i++]), current);
		current = current->next;
	}
	return (output);
}