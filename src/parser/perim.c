/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dop_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:42:00 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 15:42:30 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	ft_perim_map_dop(t_data *data, int i, int j)
{
	while (j < data->map_y)
	{
		i = 0;
		while (i < data->map_x)
		{
			if (data->map[j][i] == '0')
			{
				if (ft_perim_map_saport(data, j, i) == 1)
					ft_error(data, "perim map no valid");
			}
			i++;
		}
		j++;
	}
}

void	ft_perim_map(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (data->map[j][i] != '\0')
	{
		if (data->map[j][i] == '0')
			ft_error(data, "perim map no valid");
		i++;
	}
	i = 0;
	while (data->map[data->map_y][i] != '\0')
	{
		if (data->map[j][i] == '0')
			ft_error(data, "perim map no valid");
		i++;
	}
	ft_perim_map_dop(data, i, j);
}

void	map_init(t_data *data, int maxlen)
{
	int	a;

	a = 0;
	printf("maxlen = %d\n", maxlen);
	data->map_x = maxlen;
	printf("len_y = %d\n", data->map_y);
	data->map = (char **)malloc(data->map_y * sizeof(char *));
}
