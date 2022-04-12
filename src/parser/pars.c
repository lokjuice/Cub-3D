/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dop_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:03:26 by vtheobal          #+#    #+#             */
/*   Updated: 2022/03/21 17:16:42 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

t_data	data_init(char *str)
{
	t_data	data;

	data.map = malloc(sizeof(char));
	data.no = NULL;
	data.so = NULL;
	data.we = NULL;
	data.ea = NULL;
	data.argv = str;
	data.p_x = 0;
	data.p_y = 0;
	return (data);
}

void	pars_c_f(t_data *data, char *str)
{
	int		i;
	int		a;
	int		cnt;
	char	*arg;

	i = 1;
	a = 0;
	cnt = 0;
	arg = malloc(sizeof(char));
	while (str[i] != '\0' && cnt < 3)
	{
		while (str[i] <= '9' && str[i] >= '0')
			arg[a++] = str[i++];
		arg[a] = '\0';
		if (str[0] == 'F')
			data->f[cnt++] = ft_atoi(arg);
		if (str[0] == 'C')
			data->c[cnt++] = ft_atoi(arg);
		a = 0;
		i++;
	}
	free(arg);
}

void	put_path(char *path, t_data *data, char *str)
{
	if (str[0] == 'S' && str[1] == 'O')
		data->so = path;
	if (str[0] == 'E' && str[1] == 'A')
		data->ea = path;
	if (str[0] == 'N' && str[1] == 'O')
		data->no = path;
	if (str[0] == 'W' && str[1] == 'E')
		data->we = path;
}

void	pars_direct(t_data *data, char *str)
{
	int		i;
	int		a;
	char	*path;

	i = 0;
	a = 0;
	path = malloc(sizeof(char) * 1000);
	if (path == NULL)
		ft_error(data, "malloc");
	while (str[i] != '\0')
	{
		while (str[i] != '.')
			i++;
		while (str[i] != '\0')
		{
			path[a++] = str[i];
			i++;
		}
		path[a++] = '\0';
		i++;
	}
	put_path(path, data, str);
}
