/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 15:22:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 09:51:57 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_key_press(int keycode, t_cub *c)
{
	if (keycode == KEY_ESC)
		ft_close(c, 1);
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
	else if (keycode == KEY_LSHIFT)
		c->sprint = 2;
	return (1);
}

int		ft_key_release(int keycode, t_cub *c)
{
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
	else if (keycode == KEY_LSHIFT)
		c->sprint = 1;
	return (1);
}
