/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 04:34:17 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/11 06:15:20 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_command
{
	char		*command;
	char		*flag;
	char		*operator;
	char		**options;
}				t_command;

typedef struct s_exec
{
	struct s_exec *prev;
	t_command		*command;
	struct s_exec	*next;
}	t_exec;

// utils
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
char	**ft_split(char const *s, char c);
// tokenizer
int		is_quote(char *str);
int		is_rederection(char *str);
int		is_pipe(char *str);
int		is_command(char *str);
int		is_flag(char *str);
char	*trim_quotes(char *str);
char	*add_spaces(char *str);
void	switch_char(char *str, char to_find, char character);
char	*format(char *str);
t_exec	*new_exec(t_command *command, t_exec *prev);
t_command	*new_command(char *input);
// errors
void	error(void);

#endif