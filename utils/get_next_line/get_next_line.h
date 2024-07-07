/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:45:30 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/07 02:07:48 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# if BUFFER_SIZE >= 2147483647
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *ptr, size_t n);
int		has_newline(char *str, int *len);
char	*ft_strdup(char *s1, int should_free);
char	*ft_strjoin(char *s1, char *s2);
#endif
