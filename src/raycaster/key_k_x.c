/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_k_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:46:55 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 16:54:50 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	key_k_w(t_info *info)
{
	if (info->data.map[(int)(info->posx + info->dirx * \
		info->movespeed)][(int)(info->posy)] != '1')
		info->posx += info->dirx * info->movespeed;
	if (info->data.map[(int)(info->posx)][(int)(info->posy + \
		info->diry * info->movespeed)] != '1')
		info->posy += info->diry * info->movespeed;
}

void	key_k_s(t_info *info)
{
	if (info->data.map[(int)(info->posx - info->dirx * \
		info->movespeed)][(int)(info->posy)] != '1')
		info->posx -= info->dirx * info->movespeed;
	if (info->data.map[(int)(info->posx)][(int)(info->posy - \
		info->diry * info->movespeed)] != '1')
		info->posy -= info->diry * info->movespeed;
}

void	key_k_d(t_info *info)
{
	if (info->data.map[(int)(info->posx + info->planex * \
		info->movespeed)][(int)(info->posy)] != '1')
		info->posx += info->planex * info->movespeed;
	if (info->data.map[(int)(info->posx)][(int)(info->posy + \
		info->planey * info->movespeed)] != '1')
		info->posy += info->planey * info->movespeed;
}

void	key_k_a(t_info *info)
{
	if (info->data.map[(int)(info->posx - info->planex * \
		info->movespeed)][(int)(info->posy)] != '1')
		info->posx -= info->planex * info->movespeed;
	if (info->data.map[(int)(info->posx)][(int)(info->posy - \
		info->planey * info->movespeed)] != '1')
		info->posy -= info->planey * info->movespeed;
}
