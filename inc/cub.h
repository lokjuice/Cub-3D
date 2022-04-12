/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:30 by wroyal            #+#    #+#             */
/*   Updated: 2022/03/21 17:38:18 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/errno.h>

# define BUFFER_SIZE	42
# define SCALE 		25

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define TEXWIDTH 64
# define TEX_HEIGHT 64
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define WIDTH 640
# define HEIGHT 480
# define TEX 240

# define K_A 0
# define K_D 2
# define K_S 1
# define K_W 13
# define K_AR_L 123
# define K_AR_R 124
# define K_ESC 53

typedef struct s_milix
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		endian;
}				t_milix;

typedef struct s_ceil
{
	float	raydirx0;
	float	raydiry0;
	float	raydirx1;
	float	raydiry1;
	int		p;
	float	rowdistance;
	float	floorstepx;
	float	floorstepy;
	float	floorx;
	float	floory;
	float	posz;
}				t_ceil;

typedef struct s_data
{
	char	*argv;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	**map;
	int		p_x;
	int		p_y;
	float	p_dir;
	int		map_len;
	char	nswe;
	int		map_y;
	int		map_x;
	t_milix	*milix;
	int		size_l;
	int		bpp;
	int		maxlen;
}				t_data;

typedef struct s_dop
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		texy;
	int		texx;
	int		mapx;
	int		mapy;
	int		step;
	int		stepx;
	int		stepy;
	int		texpos;
	int		hit;
	int		side;
	int		x;
	int		color;
	int		lineheight;
	int		drawstart;
	int		drawend;
}				t_dop;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_info
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	void	*mlx;
	void	*win;
	int		buf[HEIGHT][WIDTH];
	int		**texture;
	double	movespeed;
	double	rotspeed;
	int		color_dop;
	t_dop	dop;
	t_img	img;
	t_data	data;
	t_ceil	ceil;
	t_milix	milix;
}				t_info;

//cub

size_t	ft_strlen(const char *s);
t_data	data_init(char *str);
void	ft_error(t_data *data, char *str);
void	map_format_error(char *argv);
void	pars_direct(t_data *data, char *str);
void	pars_c_f(t_data *data, char *str);
t_data	data_init(char *str);
void	put_path(char *path, t_data *data, char *str);
void	ft_print(t_data *data);
int		parser(t_data *data, char *str);
void	lexer(char *str, t_data *data);
void	error_check(char *str, t_data *data);
int		create_trgb(int t, int r, int g, int b);
void	person_position(t_data *data);
void	person_info(t_data *data);
int		ft_perim_map_saport(t_data *data, int j, int i);
void	ft_perim_map(t_data *data);
void	map_init(t_data *data, int maxlen);
void	map_reader(int fd, t_data *data, int map_start);

//raycaster

int		ft_exit(t_info *info);
void	verline(t_info *info, int x, int y1, int y2);
void	draw(t_info *info);
void	load_image(t_info *info, int *texture, char *path, t_img *img);
void	params_init(t_info *info, int x);
void	dop_ray(t_info *info);
void	dop_ray_2(t_info *info);
void	texture_dop(t_info *info, double step, int texNum, int texX);
void	mk_texture(t_info *info);
void	floor_ceil(t_info *info);
void	calc(t_info *info);
void	clear_screen(t_info *info);
void	key_k_w(t_info *info);
void	key_k_s(t_info *info);
void	key_k_d(t_info *info);
void	key_k_a(t_info *info);
void	key_k_ar_r(t_info *info);
void	key_k_ar_l(t_info *info);
int		key_press(int key, t_info *info);
int		main_loop(t_info *info);
void	init_plane(t_info *info);
void	init_dir(t_info *info);
int		ft_raycaster(t_data *data);
int		create_trgb(int t, int r, int g, int b);

//gnl

int		get_next_line(int fd, char **line);
int		has_return(char *str);
char	*join_str(const char *s1, const char *s2);

//libft

char	*ft_strchr(char *s, char c);
int		ft_atoi(const char *str);
char	*ft_strdup(char *s1);
char	*ft_bzero(char *s, size_t n);

#endif