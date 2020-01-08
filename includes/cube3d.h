/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:06:18 by tclaudel     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2020/01/07 14:35:52 by tclaudel    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2020/01/08 11:30:17 by tclaudel    ###    #+. /#+    ###.fr     */
>>>>>>> 8b52046
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
# include <math.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# include "config.h"
# include "keycode.h"

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_rgba
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgba;

typedef union		u_color
{
	int				color;
	t_rgba			rgb;
}					t_color;

typedef struct		s_cub
{
	int				*res;
	char			flag;
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
	t_pos			*start;
	char			orientation;
	t_vector		*pos;
	t_pos			*square;
	t_vector		dir;
	t_color			*color;
	t_vector		side_dist;
	t_vector		delta_dist;
	t_vector		*pla;
	double			wall;
	t_pos			*step;
	bool			hit;
	bool			side_hited;
	int				line_height;
	int				draw_start;
	int				draw_end;
	char			move;
	char			rot;
	t_vector		old_dir;
	t_vector		old_pla;
	void			*dp;
	int				*dp_data;
	int				bpp;
	int				size_line;
	int				endian;

}					t_cub;

void				ft_arg_error(char *av);
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
int					ft_launch_window(t_cub *cub);
void				ft_move(t_cub *cub);
int					main_loop(t_cub *c);

/*
**	SET STRUCT
*/

t_cub				*init_cub(void);
void				init_player(t_cub *cub);
t_color				*init_color(void);
void				init_map(t_cub *setup);

/*
**	RAYCASTING
*/

int					ft_raycasting(t_cub *cub);
void				ft_draw(t_cub *c, int x);
void				ft_rot(t_cub *c);

#endif
