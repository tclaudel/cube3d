/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:06:18 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 09:24:16 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "../libft/includes/libft.h"
# include "config.h"

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_rgb;

typedef union		u_color
{
	int				color;
	t_rgb			rgb;
}					t_color;

typedef struct		s_cub
{
	int				*res;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			**map;
	int				f;
	int				c;
	void			*mlx_ptr;
	void			*mlx_win;
	double			camera_x;
	size_t			map_width;
	size_t			map_height;
	size_t			*player_start;
	char			orientation;
	double			*player_pos;
	double			*player_dir;
	double			*plane;
	t_color			*color;
}					t_cub;

void				ft_arg_error(int ac, char *av);
int					ft_arg_analyser(int fd, t_cub *cub);
void				ft_error(char *error);
int					ft_convert_line(char *line, t_cub *cub);
void				ft_check_map(int fd, char *line, t_cub *cub);
void				ft_str_convert(char *str);

/*
**	CONVERTERS
*/

void				ft_r_convert(char **token, t_cub *cub);
void				ft_no_convert(char **token, t_cub *cub);
void				ft_so_convert(char **token, t_cub *cub);
void				ft_we_convert(char **token, t_cub *cub);
void				ft_ea_convert(char **token, t_cub *cub);
void				ft_s_convert(char **token, t_cub *cub);
void				ft_f_convert(char **token, t_cub *cub);
void				ft_c_convert(char **token, t_cub *cub);
void				ft_convert_map(char *strcub, t_cub *cub);

/*
**	CUB
*/

int					ft_cub(t_cub *cub);
int					ft_lunch_window(t_cub *cub);

/*
**	SET STRUCT
*/

t_cub				*init_cub(void);
void				init_player(t_cub *cub);
t_color				*init_color(void);
void				init_map(t_cub *setup);

#endif
