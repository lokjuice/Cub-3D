/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dop_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:12:39 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/20 16:59:05 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	parser(t_data *data, char *str)
{
	char	*dop;

	dop = str;
	if (dop[2] == '.')
		pars_direct(data, str);
	if (dop[0] == 'F' || dop[0] == 'C')
		pars_c_f(data, str);
	return (0);
}

void	lexer(char *str, t_data *data)
{
	char	*dop;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	dop = malloc(sizeof(char) * 100);
	if (dop == NULL)
		ft_error(data, "malloc");
	while (*str != '\0')
	{
		if (cnt++ >= 2)
			ft_error(data, "number of arguments");
		while (*str == ' ' && *str != '\0')
			str++;
		while (*str != ' ' && *str != '\0')
		{
			dop[i++] = *str;
			str++;
		}
	}
	dop[i] = '\0';
	parser(data, dop);
	free(dop);
}

void	error_check(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] \
			!= 'S' && str[i] != 'E' && str[i] != 'W')
			ft_error(data, "map is invalid, only 0 1 N S E W");
		i++;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
