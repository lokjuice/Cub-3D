/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_asist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:45:29 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 17:05:02 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	floor_ceil_asist_1(t_info *info, int *y)
{
	info->ceil.raydirx0 = info->dirx - info->planex;
	info->ceil.raydiry0 = info->diry - info->planey;
	info->ceil.raydirx1 = info->dirx + info->planex;
	info->ceil.raydiry1 = info->diry + info->planey;
	info->ceil.p = (*y) - HEIGHT / 2;
	info->ceil.posz = 0.5 * HEIGHT;
	info->ceil.rowdistance = info->ceil.posz / info->ceil.p;
	info->ceil.floorstepx = info->ceil.rowdistance * \
		(info->ceil.raydirx1 - info->ceil.raydirx0) / WIDTH;
	info->ceil.floorstepy = info->ceil.rowdistance * \
		(info->ceil.raydiry1 - info->ceil.raydiry0) / WIDTH;
	info->ceil.floorx = info->posx + \
		info->ceil.rowdistance * info->ceil.raydirx0;
	info->ceil.floory = info->posy + \
		info->ceil.rowdistance * info->ceil.raydiry0;
}

void	floor_ceil(t_info *info)
{
	int	floor;
	int	ceiling;
	int	y;
	int	x;

	y = 0;
	x = 0;
	floor = create_trgb(1, info->data.f[0], info->data.f[1], info->data.f[2]);
	ceiling = create_trgb(1, info->data.c[0], info->data.c[1], info->data.c[2]);
	while (y < HEIGHT)
	{
		floor_ceil_asist_1(info, &y);
		while (x < WIDTH)
		{
			info->ceil.floorx += info->ceil.floorstepx;
			info->ceil.floory += info->ceil.floorstepy;
			info->buf[y][x] = ceiling;
			info->buf[HEIGHT - y - 1][x] = floor;
			x++;
		}
		x = 0;
		y++;
	}
}

void	calc_asist(t_info *info)
{
	if (info->dop.side == 0)
		info->dop.perpwalldist = (info->dop.mapx - info->posx + \
			(1 - info->dop.stepx) / 2) / info->dop.raydirx;
	else
		info->dop.perpwalldist = (info->dop.mapy - info->posy + \
			(1 - info->dop.stepy) / 2) / info->dop.raydiry;
	info->dop.lineheight = (int)(HEIGHT / info->dop.perpwalldist);
	info->dop.drawstart = -info->dop.lineheight / 2 + HEIGHT / 2;
}

void	calc(t_info *info)
{
	floor_ceil(info);
	info->dop.x = 0;
	info->dop.color = 0;
	while (info->dop.x < WIDTH)
	{
		params_init(info, info->dop.x);
		dop_ray(info);
		dop_ray_2(info);
		calc_asist(info);
		if (info->dop.drawstart < 0)
			info->dop.drawstart = 0;
		info->dop.drawend = info->dop.lineheight / 2 + HEIGHT / 2;
		if (info->dop.drawend >= HEIGHT)
			info->dop.drawend = HEIGHT - 1;
		info->dop.color = 0x0000FF;
		if (info->dop.side == 1)
			info->dop.color = info->dop.color / 2;
		mk_texture(info);
		info->dop.x++;
	}
}

void	clear_screen(t_info *info)
{
	int	i;

	i = -1;
	info->color_dop = 0x111111;
	while (++i < WIDTH)
	{
		verline(info, i, 0, HEIGHT);
	}
}
