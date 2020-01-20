/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 12:33:03 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 10:26:56 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void		ft_display_map(t_cub *c)
{
	size_t	i;

	i = 0;
	c->mapcp[(int)c->pos.x][(int)c->pos.y] = '#';
	ft_printf("\nMAP :\n\n");
	while (i < c->map_height)
	{
		ft_printf("%s\n", c->mapcp[i]);
		i++;
	}
}

static int	ft_load_life_screen(t_cub *c)
{
	if (!(c->text[9].img =
		mlx_xpm_file_to_image(c->mlx_ptr, "./textures/death.xpm",
		&c->text[9].width, &c->text[9].height)))
		return (EXIT_FAILURE);
	if (!(c->text[9].img_data =
		(int *)mlx_get_data_addr(c->text[9].img, &c->text[9].bpp,
		&c->text[9].size_line, &c->text[9].endian)))
		return (EXIT_FAILURE);
	if (!(c->text[10].img =
		mlx_xpm_file_to_image(c->mlx_ptr, "./textures/win.xpm",
		&c->text[10].width, &c->text[10].height)))
		return (EXIT_FAILURE);
	if (!(c->text[10].img_data =
		(int *)mlx_get_data_addr(c->text[10].img, &c->text[10].bpp,
		&c->text[10].size_line, &c->text[10].endian)))
		return (EXIT_FAILURE);
	return (0);
}

int			main_loop(t_cub *c)
{
	if (c->victory)
		ft_draw_victory(c);
	if (c->life == 0)
		ft_draw_death(c, 0);
	if (c->collect == c->max_collect)
		ft_next_level(c);
	if (c->rot && c->life && !c->victory)
		ft_rot(c);
	if (c->move && c->life && !c->victory)
		ft_move(c);
	if (c->move_ad && c->life && !c->victory)
		ft_move_ad(c);
	if (c->life && !c->victory)
		ft_raycast(c);
	mlx_put_image_to_window(c->mlx_ptr, c->mlx_win, c->dp.img, 0, 0);
	return (0);
}

void		ft_copy_tab(t_cub *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	c->mapcp = (char **)malloc(sizeof(char *) * c->map_height);
	while (i < c->map_height)
	{
		j = 0;
		c->mapcp[i] = (char *)malloc(sizeof(char) * c->map_width + 1);
		while (j < c->map_width)
		{
			c->mapcp[i][j] = c->tabmap[i][j];
			j++;
		}
		c->mapcp[i][c->map_width] = 0;
		i++;
	}
}

int			ft_cub(t_cub *c)
{
	if ((c->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	init_player(c);
	ft_launch_window(c);
	ft_load_textures(c);
	if (ft_load_life_screen(c))
		ft_exit_load(c);
	if (c->flag == 's')
	{
		ft_raycast(c);
		ft_save_bitmap("screenshot.bmp", c);
		ft_close(c, 1);
	}
	mlx_hook(c->mlx_win, 2, 0, &ft_key_press, c);
	mlx_hook(c->mlx_win, 3, 0, &ft_key_release, c);
	mlx_hook(c->mlx_win, 17, 0, &ft_close, c);
	mlx_loop_hook(c->mlx_ptr, &main_loop, c);
	mlx_loop(c->mlx_ptr);
	return (1);
}
