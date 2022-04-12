/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:11:12 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 17:02:43 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	mk_texture_dop_2(t_info *info, int *texnum)
{
	if (info->dop.side == 0)
	{
		if (info->dop.stepx == 1)
			*texnum = 0;
		else
			*texnum = 1;
	}
	if (info->dop.side == 1)
	{
		if (info->dop.stepy == 1)
			*texnum = 2;
		else
			*texnum = 3;
	}			
}

void	mk_texture_dop_1(t_info *info, int *texx, int *texnum)
{
	double	step;
	int		texy;
	double	texpos;
	int		y;

	step = 1.0 * TEX_HEIGHT / info->dop.lineheight;
	texpos = (info->dop.drawstart - HEIGHT / 2 + \
		info->dop.lineheight / 2) * step;
	y = info->dop.drawstart;
	while (y < info->dop.drawend)
	{
		texy = (int)texpos & (TEX_HEIGHT - 1);
		texpos += step;
		mk_texture_dop_2(info, texnum);
		info->dop.color = info->texture[(*texnum)][TEX_HEIGHT * texy + (*texx)];
		if (info->dop.side == 1)
			info->dop.color = (info->dop.color >> 1) & 8355711;
		info->buf[y][info->dop.x] = info->dop.color;
		y++;
	}
}

void	mk_texture(t_info *info)
{
	int		texnum;
	double	wallx;
	int		texx;

	texnum = info->data.map[info->dop.mapx][info->dop.mapy] - '0';
	if (info->dop.side == 0)
		wallx = info->posy + info->dop.perpwalldist * info->dop.raydiry;
	else
		wallx = info->posx + info->dop.perpwalldist * info->dop.raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)TEXWIDTH);
	if (info->dop.side == 0 && info->dop.raydirx > 0)
		texx = TEXWIDTH - texx - 1;
	if (info->dop.side == 1 && info->dop.raydiry < 0)
		texx = TEXWIDTH - texx - 1;
	mk_texture_dop_1(info, &texx, &texnum);
}
