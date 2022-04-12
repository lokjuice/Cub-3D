/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:35:33 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 17:37:16 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_raycaster_dop_1(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->mlx = mlx_init();
	info->posx = info->data.p_x - 0.5;
	info->posy = info->data.p_y + 0.5;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			info->buf[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_raycaster_dop_2(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		while (j < TEX_HEIGHT * TEXWIDTH)
		{
			info->texture[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	load_image(info, info->texture[0], info->data.so, &info->img);
	load_image(info, info->texture[1], info->data.no, &info->img);
	load_image(info, info->texture[2], info->data.we, &info->img);
	load_image(info, info->texture[3], info->data.ea, &info->img);
	info->movespeed = 0.1;
	info->rotspeed = 0.2;
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "Raycaster");
}

void	ft_raycaster_raspars(t_info *info)
{
	init_plane(info);
	init_dir(info);
	ft_raycaster_dop_1(info);
}

int	ft_raycaster(t_data *input)
{
	t_info	info;
	int		i;

	i = 0;
	info.data = *input;
	ft_raycaster_raspars(&info);
	info.texture = (int **)malloc(sizeof(int *) * 8);
	if (info.texture == 0)
		return (-1);
	while (i < 8)
	{
		info.texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEXWIDTH));
		if (info.texture[i] == 0)
			return (-1);
		i++;
	}
	ft_raycaster_dop_2(&info);
	info.img.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, \
		&info.data.bpp, &info.data.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 17, 0, ft_exit, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
	return (0);
}
