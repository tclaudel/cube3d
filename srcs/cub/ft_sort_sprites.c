/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_sprites.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 10:35:06 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 15:19:50 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_swap_sprites(t_cub *c, int i)
{
	t_sprite	tmp;

	tmp = c->sprites[i + 1];
	c->sprites[i + 1] = c->sprites[i];
	c->sprites[i] = tmp;
}

void		ft_sort_sprites(t_cub *c)
{
	int i;

	i = 0;
	while (i < c->nb_sprites)
	{
		c->sprites[i].dist = sqrt((c->pos.x - c->sprites[i].pos.x) *
			(c->pos.x - c->sprites[i].pos.x) +
			((c->pos.y - c->sprites[i].pos.y) *
			(c->pos.y - c->sprites[i].pos.y)));
		i++;
	}
	i = 0;
	while (i < c->nb_sprites - 1)
	{
		if (c->sprites[i].dist < c->sprites[i + 1].dist)
		{
			ft_swap_sprites(c, i);
			i = 0;
		}
		i++;
	}
	i = 0;
}
