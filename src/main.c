/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:14:13 by wroyal            #+#    #+#             */
/*   Updated: 2022/03/21 16:31:20 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	storage_dop(int *i, int *fd, int *a, char **buf)
{
	while (get_next_line(*fd, buf) && *a <= *i)
	{
		(*a)++;
		free(*buf);
	}
	free(*buf);
}

int	storage(t_data *data, int i)
{
	int		fd;
	int		a;
	char	*buf;
	int		maxlen;

	a = 0;
	maxlen = 0;
	data->map_y = 0;
	fd = open(data->argv, O_RDONLY);
	if (fd <= 0)
		ft_error(data, "file does not open");
	storage_dop(&i, &fd, &a, &buf);
	while (get_next_line(fd, &buf))
	{
		if (ft_strlen(buf) > (size_t)maxlen)
			maxlen = ft_strlen(buf);
		if (buf[0] == '1' || buf[0] == ' ')
			data->map_y++;
		free(buf);
	}
	free(buf);
	close(fd);
	return (maxlen);
}

void	reader_dop(char **buf, int *cnt, int *i)
{
	if (*cnt >= 5)
		(*i)--;
	(*i)++;
	free(*buf);
}

void	reader(t_data *data)
{
	int		fd;
	int		cnt;
	char	*buf;
	int		i;

	cnt = 0;
	i = 1;
	fd = open(data->argv, O_RDONLY);
	if (fd <= 0)
		ft_error(data, "file does not open");
	while (get_next_line(fd, &buf))
	{
		if (buf[0] != '\0' && cnt <= 5)
		{
			lexer(buf, data);
			cnt++;
		}
		reader_dop(&buf, &cnt, &i);
	}
	free(buf);
	close(fd);
	data->maxlen = storage(data, i);
	map_reader(fd, data, i);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	map_format_error(argv[1]);
	data = data_init(argv[1]);
	reader(&data);
	return (0);
}
