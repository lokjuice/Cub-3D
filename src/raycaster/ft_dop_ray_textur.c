/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dop_ray_textur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:34:51 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 17:38:26 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	ft_exit(t_info *info)
{
	(void)info;
	exit(0);
	return (0);
}

void	dop_ray(t_info *info)
{
	if (info->dop.raydirx < 0)
	{
		info->dop.stepx = -1;
		info->dop.sidedistx = (info->posx - info->dop.mapx) \
			* info->dop.deltadistx;
	}
	else
	{
		info->dop.stepx = 1;
		info->dop.sidedistx = (info->dop.mapx + 1.0 - info->posx) \
			* info->dop.deltadistx;
	}
	if (info->dop.raydiry < 0)
	{
		info->dop.stepy = -1;
		info->dop.sidedisty = (info->posy - info->dop.mapy) \
			* info->dop.deltadisty;
	}
	else
	{
		info->dop.stepy = 1;
		info->dop.sidedisty = (info->dop.mapy + 1.0 - info->posy) \
			* info->dop.deltadisty;
	}
}

void	dop_ray_2(t_info *info)
{
	while (info->dop.hit == 0)
	{
		if (info->dop.sidedistx < info->dop.sidedisty)
		{
			info->dop.sidedistx += info->dop.deltadistx;
			info->dop.mapx += info->dop.stepx;
			info->dop.side = 0;
		}
		else
		{
			info->dop.sidedisty += info->dop.deltadisty;
			info->dop.mapy += info->dop.stepy;
			info->dop.side = 1;
		}
		if (info->data.map[info->dop.mapx][info->dop.mapy] == '1')
			info->dop.hit = 1;
	}
}

void	texture_dop(t_info *info, double step, int texNum, int texx)
{
	int	texpos;
	int	texy;
	int	y;

	texpos = (info->dop.drawstart - HEIGHT / 2 + \
		info->dop.lineheight / 2) * step;
	y = info->dop.drawstart;
	while (y < info->dop.drawend)
	{
		texy = (int)texpos & (TEX_HEIGHT - 1);
		texpos += step;
		info->dop.color = info->texture[texNum][TEX_HEIGHT * texy + texx];
		if (info->dop.side == 1)
			info->dop.color = (info->dop.color >> 1) & 8355711;
		info->buf[y][info->dop.x] = info->dop.color;
		y++;
	}
}
