/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:51:35 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/08 05:09:48 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

t_token	*new_token(char *value, TokenType type)
{
	t_token	*output;

	output = (t_token *)malloc(sizeof(t_token));
	if (!output)
		return (NULL);
	output->value = value;
	output->type = type;
	return (output);
}

t_input	*new_input(char *value, TokenType type,
		t_input *prev, t_input *next)
{
	t_input	*output;

	output = (t_input *)malloc(sizeof(t_input));
	if (!output)
		return (NULL);
	output->prev = prev;
	output->token = new_token(value, type);
	output->next = next;
	return (output);
}

t_input *tokenizer(int argc, char *argv[])
{
	t_input		*output;
	int		i;

	i = 0;
	while (i <= argc)
	{
		if (is_command(argv[i]))
			
		i++;
	}
}
