/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:11:09 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/20 18:13:37 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	key_press(int key, t_info *info)
{
	if (key == K_W)
		key_k_w(info);
	if (key == K_S)
		key_k_s(info);
	if (key == K_D)
		key_k_d(info);
	if (key == K_A)
		key_k_a(info);
	if (key == K_AR_R)
		key_k_ar_r(info);
	if (key == K_AR_L)
		key_k_ar_l(info);
	if (key == K_ESC)
		exit(0);
	return (0);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

void	init_plane(t_info *info)
{
	if (info->data.nswe == 'N')
	{
		info->dirx = -1;
		info->diry = 0;
	}
	if (info->data.nswe == 'S')
	{
		info->dirx = 1;
		info->diry = 0;
	}
	if (info->data.nswe == 'W')
	{
		info->dirx = 0;
		info->diry = -1;
	}
	if (info->data.nswe == 'E')
	{
		info->dirx = 0;
		info->diry = 1;
	}
}

void	init_dir(t_info *info)
{
	if (info->data.nswe == 'N')
	{
		info->planex = 0;
		info->planey = 0.66;
	}
	if (info->data.nswe == 'S')
	{
		info->planex = 0;
		info->planey = -0.66;
	}
	if (info->data.nswe == 'W')
	{
		info->planex = -0.66;
		info->planey = 0;
	}
	if (info->data.nswe == 'E')
	{
		info->planex = 0.66;
		info->planey = 0;
	}
}
