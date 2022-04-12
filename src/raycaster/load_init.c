/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:15:09 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 17:02:46 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	verline(t_info *info, int x, int y1, int y2)
{
	int	y;
	int	color;

	color = info->color_dop;
	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

void	draw(t_info *info)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path, \
		&img->img_width, &img->img_height);
	if (img->img == 0)
		ft_error(&info->data, "image not open");
	img->data = (int *)mlx_get_data_addr(img->img, \
		&info->data.bpp, &info->data.size_l, &img->endian);
	while (y < img->img_height)
	{
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	params_init(t_info *info, int x)
{
	info->dop.camerax = 2 * x / (double)WIDTH - 1;
	info->dop.raydirx = info->dirx + info->planex * info->dop.camerax;
	info->dop.raydiry = info->diry + info->planey * info->dop.camerax;
	info->dop.mapx = (int)info->posx;
	info->dop.mapy = (int)info->posy;
	info->dop.deltadistx = fabs(1 / info->dop.raydirx);
	info->dop.deltadisty = fabs(1 / info->dop.raydiry);
	info->dop.hit = 0;
}
