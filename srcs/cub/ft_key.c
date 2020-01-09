/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 15:22:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 16:55:28 by tclaudel    ###    #+. /#+    ###.fr     */
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
