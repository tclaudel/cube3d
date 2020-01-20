/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 15:22:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 10:33:29 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_edit_map(int keycode, t_cub *c)
{
	int		square;

	if (keycode == KEY_0)
		square = '0';
	else if (keycode == KEY_5)
		square = '5';
	else
		square = '0' + (int)keycode - 17;
	if ((c->pos.x + c->dir.x > 0 && c->pos.y + c->dir.y > 0 &&
		c->pos.x + c->dir.x < (int)(c->map_height - 1) &&
		c->pos.y + c->dir.y < (int)(c->map_width - 1)))
		c->tabmap[(int)(c->pos.x + c->dir.x)]
			[(int)(c->pos.y + c->dir.y)] = square;
}

int				ft_key_press(int keycode, t_cub *c)
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

int				ft_key_release(int keycode, t_cub *c)
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
	else if (c->flag == 'e' && (keycode == KEY_0 || keycode == KEY_1 ||
		keycode == KEY_2 || keycode == KEY_3 || keycode == KEY_4 ||
		keycode == KEY_5))
		ft_edit_map(keycode, c);
	return (1);
}
