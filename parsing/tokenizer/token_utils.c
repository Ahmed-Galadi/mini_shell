/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 04:23:19 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/16 06:20:06 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	redirection_init(t_opperator *opp, char *file, char *type)
{
	opp->delimiter = NULL;
	if (!file)
		opp->file = NULL;
	else
		opp->file = file;
	if (ft_strcmp(type, "in"))
		opp->type = red_in;
	if (ft_strcmp(type, "out"))
		opp->type = red_out;
	if (ft_strcmp(type, "app"))
		opp->type = append_out;
}

void	heredoc_init(t_opperator *opp, char *delimiter)
{
	opp->file = NULL;
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
	t_opperator *new_op;
	if (is_rederection(splited_input[*i]))
	{
		if (!(output_command->operator))
			output_command->operator = new_operator(splited_input[*i], splited_input, *i);
		else
		{
			new_op = new_operator(splited_input[*i], splited_input, *i);
			add_lstback(output_command->operator, new_op);
		}
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
	i = 0;
	while (splited_input[i])
		switch_char(splited_input[i++], -1, ' ');
	output = (t_command *)malloc(sizeof(t_command));
	if (!output)
		return (NULL);
	i = 0;
	output->command = splited_input[i++];
	new_flag(output, splited_input, &i);
	new_redirection(output, splited_input, &i);
	new_options(output, splited_input, &i);
	return (output);
}
// void	redirection_init(t_opperator *opp, char *file, char *type)
// {
// 	opp->delimiter = NULL;
// 	if (!file)
// 		opp->file = NULL;
// 	else
// 		opp->file = file;
// 	if (ft_strcmp(type, "in"))
// 		opp->type = red_in;
// 	if (ft_strcmp(type, "out"))
// 		opp->type = red_out;
// 	if (ft_strcmp(type, "app"))
// 		opp->type = append_out;
// }

// void	heredoc_init(t_opperator *opp, char *delimiter)
// {
// 	opp->file = NULL;
// 	if (!delimiter)
// 		opp->delimiter = NULL;
// 	else
// 		opp->delimiter = delimiter;
// 	opp->type = here_doc;
// }



// t_opperator *new_operator(char *operator, char *file)
// {
// 	t_opperator	*output;

// 	output = (t_opperator *)malloc(sizeof(t_opperator));
// 	if (!output)
// 		return (NULL);
// 	if (ft_strcmp(operator, ">"))
// 		redirection_init(output, file, "out");
// 	if (ft_strcmp(operator, "<"))
// 		redirection_init(output, file, "in");
// 	if (ft_strcmp(operator, ">>"))
// 		redirection_init(output, file, "app");
// 	if (ft_strcmp(operator, "<<"))
// 		heredoc_init(output, file);
// 	output->next = NULL;
// 	return (output);
// }

// void	new_redirection(t_command **command, char *redirection, char *file)
// {
// 	t_opperator *current;

// 	current = (*command)->operator;
// 	if (!current)
// 		current = new_operator(redirection, file);
// 	else
// 	{
// 		while (current->next)
// 			current = current->next;
// 		current->next = new_operator(redirection, file);
// 	}
// }

// void	new_options(t_command **command, char **splited_input, int *i)
// {
// 	int		j;

// 	j = 0;
// 	(*command)->options = (char **)malloc(sizeof(char *) * 100);
// 	while (splited_input[*i])
// 	{
// 		if (is_rederection(splited_input[*i]))
// 		{
// 			new_redirection(command, splited_input[*i], splited_input[(*i) + 1]);
// 			*i += 2;
// 		}
// 		else
// 		{
// 			(*command)->options[j] = splited_input[*i];
// 			*i += 1;
// 			j++;
// 		}
// 	}
// 	(*command)->options[j] = NULL;
// }

// void	new_flag(t_command **command, char **splited_input, int *i)
// {
// 	char	**output;
// 	int		count;
// 	int		j;

// 	j = *i;
// 	count = 0;
// 	while (is_flag(splited_input[j++]))
// 		count++;
// 	output = (char **)malloc(count * sizeof(char *));
// 	if (!output)
// 		error();
// 	j = 0;
// 	while (is_flag(splited_input[*i]))
// 	{
// 		output[j] = splited_input[*i];
// 		*i += 1;
// 		j++;
// 	}
// 	output[j] = NULL;
// 	(*command)->flag = output;
// }


// t_command	*new_command(char *input)
// {
// 	t_command	*output;
// 	char		**splited_input;
// 	int			i;
	
// 	switch_char(input, -1, '|');
// 	switch_char(input, ' ', -1);
// 	splited_input = ft_split(input, ' ');
// 	i = 0;
// 	while (splited_input[i])
// 		switch_char(splited_input[i++], -1, ' ');
// 	output = (t_command *)malloc(sizeof(t_command));
// 	if (!output)
// 		return (NULL);
// 	i = 0;

// 	output->command = splited_input[i++];
// 	new_flag(&output, splited_input, &i);
// 	new_options(&output, splited_input, &i);
// 	return (output);
// }
