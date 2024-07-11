/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 04:34:17 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/11 04:22:24 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum
{
	QUOTES,
	REDIRECTIONS,
	PIPES,
	COMMAND,
	FLAG,
	STRING,
	EMPTY,
} TokenType;

typedef struct	s_command
{
	char		*command;
	char		*flag;
	char		*operator;
	char		**options;
	int			is_piped;
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
char	*format(char *str);
// errors
void	error(void);

#endif