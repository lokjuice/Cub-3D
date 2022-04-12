/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dop_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:26:35 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/20 16:57:35 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	person_position(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_len)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' \
				|| data->map[y][x] == 'W' || data->map[y][x] == 'E')
			{
				data->p_x = (x + 1);
				data->p_y = y;
				data->nswe = data->map[y][x];
				data->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	person_info(t_data *data)
{
	if (data->nswe == 'N')
		data->p_dir = M_PI_2 * 3;
}

int	ft_perim_map_saport(t_data *data, int j, int i)
{
	int	n;
	int	g;

	n = 0;
	g = 0;
	i = i + 2;
	j--;
	while (n < 3)
	{
		g = 0;
		i = i - 3;
		while (g < 3)
		{
			if (data->map[j][i] == ' ')
				return (1);
			g++;
			i++;
		}
		n++;
		j++;
	}
	return (0);
}
