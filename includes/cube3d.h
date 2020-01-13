/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:06:18 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 17:06:55 by tclaudel    ###    #+. /#+    ###.fr     */
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

typedef struct		s_sprite
{
	t_vector		pos;
	double			dist;
}					t_sprite;

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

typedef struct		s_img
{
	void			*img;
	int				width;
	int				height;
	int				*img_data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_cub
{
	int				*res;
	char			flag;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			**tabmap;
	int				f;
	int				c;
	void			*mlx_ptr;
	void			*mlx_win;
	double			camera_x;
	size_t			map_width;
	size_t			map_height;
	t_pos			*start;
	char			orientation;
	t_vector		pos;
	t_vector		plane;
	t_pos			map;
	t_vector		dir;
	t_vector		ray_dir;
	t_color			*color;
	t_vector		side_dist;
	t_vector		delta_dist;
	double			wall_dist;
	t_pos			step;
	bool			hit;
	bool			side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	char			move;
	char			rot;
	t_vector		o_dir;
	t_vector		o_pla;
	t_img			dp;
	t_img			text[5];
	int				tex_nb;
	double			wall_pos;
	int				wall_dir;
	int				tex_x;
	int				tex_y;
	double			text_step;
	double			text_pos;
	t_sprite		*sprites;
	int				nb_sprites;
	t_vector		sprite;
	char			**mapcp;
	double			inv_det;
	double			*zbuffer;
	t_vector		transform;
	double			sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	t_pos			draw_sprite_start;
	t_pos			draw_sprite_end;

}					t_cub;

void				ft_arg_error(char *av);
int					ft_arg_analyser(int fd, t_cub *cub);
void				ft_error(char *error);
int					ft_convert_line(char *line, t_cub *cub);
void				ft_check_map(int fd, char *line, t_cub *cub);
void				ft_str_convert(char *str);
void				ft_set_sprites(t_cub *c);
void				ft_raycast_sprites(t_cub *c);

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
void				ft_load_textures(t_cub *c);
void				ft_display_map(t_cub *c);
int					ft_close(t_cub *c);
int					ft_key_press(int keycode, t_cub *c);
int					ft_key_release(int keycode, t_cub *c);
void				ft_copy_tab(t_cub *c);
void				ft_sort_sprites(t_cub *c);
void				ft_draw_sprite(t_cub *c);

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

void				ft_raycast(t_cub *c);
void				ft_draw(t_cub *c, int x);
void				ft_rot(t_cub *c);

#endif
