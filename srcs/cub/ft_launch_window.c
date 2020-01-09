/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_launch_window.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 16:06:01 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_close(t_cub *c)
{
	mlx_destroy_window(c->mlx_ptr, c->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_key_press(int keycode, t_cub *c)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(c->mlx_ptr, c->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_W)
		c->move = 'W';
	else if (keycode == KEY_S)
		c->move = 'S';
	else if (keycode == KEY_A)
		c->rot = 'A';
	else if (keycode == KEY_D)
		c->rot = 'D';
	return (1);
}

int		ft_key_release(int keycode, t_cub *c)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(c->mlx_ptr, c->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_W)
		c->move = 0;
	else if (keycode == KEY_S)
		c->move = 0;
	else if (keycode == KEY_A)
		c->rot = 0;
	else if (keycode == KEY_D)
		c->rot = 0;
	return (1);
}

int		ft_launch_window(t_cub *c)
{
	ft_printf("-->\tlaunching window (%d * %d)\n", c->res[0], c->res[1]);
	if (!(c->dp.img= mlx_new_image(c->mlx_ptr, c->res[0], c->res[1])))
		return (EXIT_FAILURE);
	if (!(c->dp.img_data =
		(int *)mlx_get_data_addr(c->dp.img, &c->dp.bpp,
		&c->dp.size_line, &c->dp.endian)))
		return (EXIT_FAILURE);
	if ((c->mlx_win =
		mlx_new_window(c->mlx_ptr, c->res[0], c->res[1], "CUB 3D")) == NULL)
		return (EXIT_FAILURE);
	mlx_hook(c->mlx_win, 2, 0, &ft_key_press, c);
	mlx_hook(c->mlx_win, 3, 0, &ft_key_release, c);
	mlx_hook(c->mlx_win, 17, 0, &ft_close, c);
	mlx_loop_hook(c->mlx_ptr, &main_loop, c);
	mlx_loop(c->mlx_ptr);
	return (EXIT_SUCCESS);
}