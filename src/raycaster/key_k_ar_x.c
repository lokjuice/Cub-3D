/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_k_ar_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:06:23 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 16:55:21 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	key_k_ar_r(t_info *info)
{
	double	olddirx;
	double	oldplanex;

	olddirx = info->dirx;
	info->dirx = info->dirx * cos(-info->rotspeed) - \
		info->diry * sin(-info->rotspeed);
	info->diry = olddirx * sin(-info->rotspeed) + \
		info->diry * cos(-info->rotspeed);
	oldplanex = info->planex;
	info->planex = info->planex * cos(-info->rotspeed) - \
		info->planey * sin(-info->rotspeed);
	info->planey = oldplanex * sin(-info->rotspeed) + \
		info->planey * cos(-info->rotspeed);
}

void	key_k_ar_l(t_info *info)
{
	double	olddirx;
	double	oldplanex;

	olddirx = info->dirx;
	info->dirx = info->dirx * cos(info->rotspeed) - \
		info->diry * sin(info->rotspeed);
	info->diry = olddirx * sin(info->rotspeed) + \
		info->diry * cos(info->rotspeed);
	oldplanex = info->planex;
	info->planex = info->planex * cos(info->rotspeed) - \
		info->planey * sin(info->rotspeed);
	info->planey = oldplanex * sin(info->rotspeed) + \
		info->planey * cos(info->rotspeed);
}
