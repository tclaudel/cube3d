/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 15:22:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 15:27:37 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

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
		c->move_ad = 'A';
	else if (keycode == KEY_D)
		c->move_ad = 'D';
	else if (keycode == ARROW_LEFT)
		c->rot = 'E';
	else if (keycode == ARROW_RIGHT)
		c->rot = 'Q';
	return (1);
}

int		ft_key_release(int keycode, t_cub *c)
{
	if (keycode == KEY_ESC)
		ft_close(c);
	if (keycode == KEY_W)
		c->move = 0;
	else if (keycode == KEY_S)
		c->move = 0;
	else if (keycode == KEY_A)
		c->move_ad = 0;
	else if (keycode == KEY_D)
		c->move_ad = 0;
	else if (keycode == ARROW_LEFT)
		c->rot = 0;
	else if (keycode == ARROW_RIGHT)
		c->rot = 0;
	return (1);
}
