/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:25:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 16:47:39 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_hint_spr(t_cub *c)
{
	if (c->tabmap[(int)c->pos.x][(int)c->pos.y] &&
		(((c->pos.x - (int)c->pos.x) > 0.3 ||
		(c->pos.x - (int)c->pos.x) < 0.7) &&
		(((c->pos.y - (int)c->pos.y) > 0.3) ||
		((c->pos.y - (int)c->pos.y) > 0.7))))
		{
			if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '2')
				return (1);
			if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '3')
			{
				if (c->life < c->maxlife)
					c->life += 10;
				c->tabmap[(int)c->pos.x][(int)c->pos.y] = '0';
				return (0);
			}
			if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '4')
			{
				if (c->life > 0)
					c->life -= 10;
					c->tabmap[(int)c->pos.x][(int)c->pos.y] = '0';
				return (1);
			}
			if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '5')
			{
				if (c->life > 0)
					c->collect++;
					c->tabmap[(int)c->pos.x][(int)c->pos.y] = '0';
				return (1);
			}
			else
				return (0);
			
		}
	else
		return (0);
}

void	ft_move_ad(t_cub *c)
{
	if (c->flag == 'm')
	{
		ft_copy_tab(c);
		ft_display_map(c);
	}
	if (c->move_ad == 'D')
	{
		c->pos.x += c->plane.x * MOVSPEED * c->sprint;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1' || ft_hint_spr(c))
			c->pos.x -= c->plane.x * MOVSPEED * c->sprint;
		c->pos.y += c->plane.y * MOVSPEED * c->sprint;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1' || ft_hint_spr(c))
			c->pos.y -= c->plane.y * MOVSPEED * c->sprint;
	}
	else if (c->move_ad == 'A')
	{
		c->pos.x -= c->plane.x * MOVSPEED * c->sprint;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1' || ft_hint_spr(c))
			c->pos.x += c->plane.x * MOVSPEED * c->sprint;
		c->pos.y -= c->plane.y * MOVSPEED * c->sprint;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1' || ft_hint_spr(c))
			c->pos.y += c->plane.y * MOVSPEED * c->sprint;
	}
}

void	ft_move(t_cub *c)
{
	if (c->flag == 'm')
	{
		ft_copy_tab(c);
		ft_display_map(c);
	}
	if (c->move == 'W')
	{
		c->pos.x += c->dir.x * MOVSPEED * c->sprint;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1' || ft_hint_spr(c))
			c->pos.x -= c->dir.x * MOVSPEED * c->sprint;
		c->pos.y += c->dir.y * MOVSPEED * c->sprint;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1' || ft_hint_spr(c))
			c->pos.y -= c->dir.y * MOVSPEED * c->sprint;
	}
	else if (c->move == 'S')
	{
		c->pos.x -= c->dir.x * MOVSPEED * c->sprint;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1' || ft_hint_spr(c))
			c->pos.x += c->dir.x * MOVSPEED * c->sprint;
		c->pos.y -= c->dir.y * MOVSPEED * c->sprint;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1' || ft_hint_spr(c))
			c->pos.y += c->dir.y * MOVSPEED * c->sprint;
	}
}

void	ft_rot(t_cub *c)
{
	c->o_dir.x = c->dir.x;
	c->o_pla.x = c->plane.x;
	if (c->rot == 'Q')
	{
		c->dir.x = c->dir.x * cos(-ROTSPEED) - c->dir.y * sin(-ROTSPEED);
		c->dir.y = c->o_dir.x * sin(-ROTSPEED) + c->dir.y * cos(-ROTSPEED);
		c->plane.x = c->plane.x * cos(-ROTSPEED) - c->plane.y * sin(-ROTSPEED);
		c->plane.y = c->o_pla.x * sin(-ROTSPEED) + c->plane.y * cos(-ROTSPEED);
	}
	else if (c->rot == 'E')
	{
		c->dir.x = c->dir.x * cos(ROTSPEED) - c->dir.y * sin(ROTSPEED);
		c->dir.y = c->o_dir.x * sin(ROTSPEED) + c->dir.y * cos(ROTSPEED);
		c->plane.x = c->plane.x * cos(ROTSPEED) - c->plane.y * sin(ROTSPEED);
		c->plane.y = c->o_pla.x * sin(ROTSPEED) + c->plane.y * cos(ROTSPEED);
	}
}
