/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dop_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:36:37 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 15:42:17 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	map_reader_dop_1(t_data *data, char *buf, int *j)
{
	int	d;

	d = 0;
	error_check(buf, data);
	data->map[*j] = (char *)malloc(data->maxlen * sizeof(char));
	if ((int)ft_strlen(buf) < data->maxlen)
	{
		data->map[*j] = ft_bzero(data->map[*j], data->maxlen);
		while (d < ((int)ft_strlen(buf)))
		{
			data->map[*j][d] = buf[d];
			d++;
		}
		d = 0;
	}
	else
		data->map[*j] = buf;
	printf("%s\n", data->map[*j]);
	data->map_len++;
	(*j)++;
}

void	map_reader_dop_2(t_data *data, int *j, char *buf)
{
	error_check(buf, data);
	data->map[*j] = buf;
	ft_perim_map(data);
	person_position(data);
	person_info(data);
	free(buf);
	ft_raycaster(data);
	j = 0;
}

void	map_reader(int fd, t_data *data, int map_start)
{
	char	*buf;
	int		j;
	int		a;

	data->map_len = 0;
	j = 0;
	a = 0;
	fd = open(data->argv, O_RDONLY);
	if (fd <= 0)
		ft_error(data, "file does not open");
	while (get_next_line(fd, &buf) && a <= map_start)
	{
		a++;
		free(buf);
	}
	free(buf);
	map_init(data, data->maxlen);
	while (get_next_line(fd, &buf))
	{
		if (ft_strlen(buf) > 1)
			map_reader_dop_1(data, buf, &j);
	}
	map_reader_dop_2(data, &j, buf);
	close(fd);
}
