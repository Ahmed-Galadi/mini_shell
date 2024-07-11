/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:31:36 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/11 02:33:57 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int main(int argc, char *argv[])
{
	char *str = argv[1];
	if (argc == 2)
	{
		char *formated_str = format(str);
		char **splited_str = ft_split(formated_str, '|');
		int i = 0;
		while (splited_str[i])
		{
			printf("%s\n", splited_str[i]);
			i++;
		}
	}
	else
		printf("error\n");
	return (0);
}