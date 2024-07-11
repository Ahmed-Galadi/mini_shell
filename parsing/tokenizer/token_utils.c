/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 04:23:19 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/11 04:30:36 by agaladi          ###   ########.fr       */
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
}