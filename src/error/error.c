/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:49:58 by wroyal            #+#    #+#             */
/*   Updated: 2022/03/19 15:55:02 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	map_format_error(char *argv)
{
	char	*cub;

	cub = ".cub";
	while (*argv != '.')
		argv++;
	while (*argv != '\0')
	{
		if (*argv != *cub)
		{
			write(1, "Error: map format is .cub\n", 26);
			exit(0);
		}
		argv++;
		cub++;
	}
}

void	ft_error(t_data *data, char *str)
{
	(void)data;
	write(1, "Error: ", 7);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}
