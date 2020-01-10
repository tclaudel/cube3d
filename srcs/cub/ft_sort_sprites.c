/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_sprites.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 10:35:06 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 10:57:16 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_sort_sprites(t_cub *c)
{
	int i;

	i = 0;
	while(i < c->nb_sprites)
	{
		c->sprites[i].dist = sqrt((c->pos.x - c->sprites[i].pos.x) * (c->pos.x - c->sprites[i].pos.x) + ((c->pos.y - c->sprites[i].pos.y) * (c->pos.y - c->sprites[i].pos.y)));
		i++;
	}
}