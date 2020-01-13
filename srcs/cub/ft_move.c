/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:25:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 16:22:35 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_move_ad(t_cub *c)
{
	if (c->flag == 'm')
	{
		ft_copy_tab(c);
		ft_display_map(c);
	}
	if (c->move_ad == 'D')
	{
		c->pos.x += c->plane.x * MOVSPEED;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x -= c->plane.x * MOVSPEED;
		c->pos.y += c->plane.y * MOVSPEED;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y -= c->plane.y * MOVSPEED;
	}
	else if (c->move_ad == 'A')
	{
		c->pos.x -= c->plane.x * MOVSPEED;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x += c->plane.x * MOVSPEED;
		c->pos.y -= c->plane.y * MOVSPEED;
		if (c->tabmap[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y += c->plane.y * MOVSPEED;
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
