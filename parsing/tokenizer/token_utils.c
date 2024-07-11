/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 04:23:19 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/11 06:51:37 by agaladi          ###   ########.fr       */
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

void	add_option()
{}

t_command	*new_command(char *input)
{
	t_command	*output;
	char		**splited_input;
	int			i;
	
	switch_char(input, -1, '|');
	switch_char(input, ' ', -1);
	splited_input = ft_split(input, ' ');
	output = (t_command *)malloc(sizeof(t_command));
	i = 0;
	while (splited_input[i])
	{
		if (is_command(splited_input[i]))
			output->command = splited_input[i];
		if (is_flag(splited_input[i]))
			output->flag = splited_input[i];
		if (is_rederection(splited_input[i]))
			output->operator = splited_input[i];
		if (i != 0)
			add_option(output ,splited_input[i]); // TODO
		i++;
	}
}
