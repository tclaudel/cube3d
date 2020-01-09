/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:25:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 17:04:04 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_move(t_cub *c)
{
	ft_display_map(c);
	if (c->move == 'W')
	{
		c->pos.x += c->dir.x * MOVSPEED;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x -= c->dir.x * MOVSPEED;
		c->pos.y += c->dir.y * MOVSPEED;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y -= c->dir.y * MOVSPEED;
	}
	else if (c->move == 'S')
	{
		c->pos.x -= c->dir.x * MOVSPEED;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x += c->dir.x * MOVSPEED;
		c->pos.y -= c->dir.y * MOVSPEED;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y += c->dir.y * MOVSPEED;
	}
}

void	ft_rot(t_cub *c)
{
	c->o_dir.x = c->dir.x;
	c->o_pla.x = c->plane.x;
	if (c->rot == 'D')
	{
		c->dir.x = c->dir.x * cos(-ROTSPEED) - c->dir.y * sin(-ROTSPEED);
		c->dir.y = c->o_dir.x * sin(-ROTSPEED) + c->dir.y * cos(-ROTSPEED);
		c->plane.x = c->plane.x * cos(-ROTSPEED) - c->plane.y * sin(-ROTSPEED);
		c->plane.y = c->o_pla.x * sin(-ROTSPEED) + c->plane.y * cos(-ROTSPEED);
	}
	else if (c->rot == 'A')
	{
		c->dir.x = c->dir.x * cos(ROTSPEED) - c->dir.y * sin(ROTSPEED);
		c->dir.y = c->o_dir.x * sin(ROTSPEED) + c->dir.y * cos(ROTSPEED);
		c->plane.x = c->plane.x * cos(ROTSPEED) - c->plane.y * sin(ROTSPEED);
		c->plane.y = c->o_pla.x * sin(ROTSPEED) + c->plane.y * cos(ROTSPEED);
	}
}
