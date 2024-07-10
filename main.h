/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 04:34:17 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/10 00:08:31 by agaladi          ###   ########.fr       */
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
} TokenType;

typedef struct s_token
{
	TokenType	type;
	char		*value;
} t_token;

typedef struct s_input
{
	struct s_input *prev;
	t_token *token;
	struct s_input	*next;
}	t_input;

// string utils
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
// tokenizer
int	is_quote(char *str);
int	is_rederection(char *str);
int	is_pipe(char *str);
int	is_command(char *str);
int	is_flag(char *str);

#endif