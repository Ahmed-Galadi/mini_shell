/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:42:53 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/10 06:56:23 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static void	mask_pipes(char *str)
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