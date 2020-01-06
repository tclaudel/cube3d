/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:25:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 17:55:43 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_can_move(t_cub *c, char option)
{
	printf("Case [%c] %f x %f\n", c->map[(int)(c->pos->x)][(int)c->pos->y], (c->pos->x + c->dir.x * MOVSPEED), c->pos->y);
	if (option == 'x')
	{
		if (!(c->map[(int)(c->pos->x)][(int)(c->pos->y)] && c->move == 'W'))
			c->pos->x -= c->dir.x * MOVSPEED;
	}
	if (option == 'y')
	{
		if (!(c->map[(int)(c->pos->x)][(int)(c->pos->y)] && c->move == 'W'))
			c->pos->y -= c->dir.y * MOVSPEED;
	}
}

void	ft_move(t_cub *c)
{
	if (c->move == 'W')
	{
		c->pos->x += c->dir.x * MOVSPEED;
		c->pos->y += c->dir.y * MOVSPEED;
	}
	else if (c->move == 'S')
	{
		c->pos->x -= c->dir.x * MOVSPEED;
		c->pos->y -= c->dir.y * MOVSPEED;
	}
}

void	ft_rot(t_cub *c)
{
	c->old_dir.x = c->dir.x;
	c->old_pla.x = c->pla->x;
	if (c->rot == 'A')
	{
		c->dir.x = c->dir.x * cos(-ROTSPEED) - c->dir.y * sin(-ROTSPEED);
		c->dir.y = c->old_dir.x * sin(-ROTSPEED) + c->dir.y * cos(-ROTSPEED);
		c->pla->x = c->pla->x * cos(-ROTSPEED) - c->pla->y * sin(-ROTSPEED);
		c->pla->y = c->old_pla.x * sin(-ROTSPEED) + c->pla->y * cos(-ROTSPEED);
	}
	else if (c->rot == 'D')
	{
		c->dir.x = c->dir.x * cos(ROTSPEED) - c->dir.y * sin(ROTSPEED);
		c->dir.y = c->old_dir.x * sin(ROTSPEED) + c->dir.y * cos(ROTSPEED);
		c->pla->x = c->pla->x * cos(ROTSPEED) - c->pla->y * sin(ROTSPEED);
		c->pla->y = c->old_pla.x * sin(ROTSPEED) + c->pla->y * cos(ROTSPEED);
	}
}
