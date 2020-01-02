/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:06:18 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 14:39:15 by tclaudel    ###    #+. /#+    ###.fr     */
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

typedef struct		s_cube3d
{
	int				*r;
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
}					t_cube3d;

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

typedef struct		s_map
{
	char			**map;
	size_t			width;
	size_t			height;
	size_t			*player;
	char			orientation;
}					t_map;

typedef struct		s_player
{
	float			pos_x;
	float			pos_y;
	float			*v_dir;
	float			*plane;
}					t_player;

typedef struct		s_meta
{
	t_cube3d		*cub;
	t_color			*color;
	t_map			*map;
	t_player		*player;
}					t_meta;

void				ft_arg_error(int ac, char *av);
int					ft_arg_analyser(int fd, t_meta *meta);
void				ft_error(char *error);
int					ft_convert_line(char *line, t_meta *meta);
void				ft_check_map(int fd, char *line);
void				ft_str_convert(char *str);

/*
**	CONVERTERS
*/

void				ft_r_convert(char **token, t_cube3d *cub);
void				ft_no_convert(char **token, t_cube3d *cub);
void				ft_so_convert(char **token, t_cube3d *cub);
void				ft_we_convert(char **token, t_cube3d *cub);
void				ft_ea_convert(char **token, t_cube3d *cub);
void				ft_s_convert(char **token, t_cube3d *cub);
void				ft_f_convert(char **token, t_cube3d *cub, t_color *color);
void				ft_c_convert(char **token, t_cube3d *cub, t_color *color);
char				**ft_convert_map(char *strmap, t_map *map);

/*
**	CUB
*/

int					ft_cub(t_meta *meta);
int					ft_lunch_window(t_cube3d *cub);

/*
**	SET STRUCT
*/

t_meta				*init_meta(void);
t_cube3d			*init_cub3d(void);
t_color				*init_color(void);
t_map				*init_map(void);
t_player			*init_player(t_map *map);

#endif
