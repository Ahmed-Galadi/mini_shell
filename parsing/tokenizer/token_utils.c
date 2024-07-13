/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 04:23:19 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/13 08:18:09 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"


void	redirection_init(t_opperator *opp, char *file, char *type)
{
	opp->delimiter = NULL;
	if (!file)
		opp->out_file = NULL;
	else
		opp->out_file = file;
	if (ft_strcmp(type, "in"))
		opp->type = red_in;
	if (ft_strcmp(type, "out"))
		opp->type = red_out;
	if (ft_strcmp(type, "app"))
		opp->type = append_out;
}

void	heredoc_init(t_opperator *opp, char *delimiter)
{
	opp->out_file = NULL;
	if (!delimiter)
		opp->delimiter = NULL;
	else
		opp->delimiter = delimiter;
	opp->type = here_doc;
}

t_opperator *new_operator(char *operator, char **input, int i)
{
	t_opperator	*output;

	output = (t_opperator *)malloc(sizeof(t_opperator));
	if (!output)
		return (NULL);
	if (ft_strcmp(operator, ">"))
		redirection_init(output, input[i + 1], "out");
	if (ft_strcmp(operator, "<"))
		redirection_init(output, input[i + 1], "in");
	if (ft_strcmp(operator, ">>"))
		redirection_init(output, input[i + 1], "app");
	if (ft_strcmp(operator, "<<"))
		heredoc_init(output, input[i + 1]);
	return (output);
}

void	new_flag(t_command *output_command, char **splited_input, int *i)
{
	int		count;
	int		j;

	count = 0;
	j = *i;
	while (is_flag(splited_input[j++]))
		count++;
	output_command->flag = (char **)malloc((count + 1) * sizeof(char *));
	if (!(output_command->flag))
		error();
	j = 0;
	while (splited_input[*i])
	{
		if (is_flag(splited_input[*i]))
		{
			output_command->flag[j++] = splited_input[*i];
			*i += 1;
		}
		else
			break;
	}
	output_command->flag[j] = NULL;
}

void	new_redirection(t_command *output_command, char **splited_input, int *i)
{
	if (is_rederection(splited_input[*i]))
	{
		output_command->operator = new_operator(splited_input[*i], splited_input, *i);
		*i += 2;
	}
}

void	new_options(t_command *output_command, char **splited_input, int *i)
{
	int		count;
	int		j;

	count = 0;
	j = *i;
	if (!splited_input[j])
		return ;
	while (splited_input[j++])
		count++;
	output_command->options = (char **)malloc((count + 1) * sizeof(char *));
	if (!(output_command->options))
		error();
	j = 0;
	while (splited_input[*i])
	{
		if (is_rederection(splited_input[*i]))
			new_redirection(output_command, splited_input, i);
		else
		{
			output_command->options[j++] = splited_input[*i];
			*i += 1;
		}
	}
	output_command->options[j] = NULL;
}




t_command	*new_command(char *input)
{
	t_command	*output;
	char		**splited_input;
	int			i;
	
	switch_char(input, -1, '|');
	switch_char(input, ' ', -1);
	splited_input = ft_split(input, ' ');
	output = (t_command *)malloc(sizeof(t_command));
	if (!output)
		return (NULL);
	i = 0;
	output->command = splited_input[i++];
	new_flag(output, splited_input, &i);
	//new_redirection(output, splited_input, &i);
	new_options(output, splited_input, &i);
	return (output);
}
