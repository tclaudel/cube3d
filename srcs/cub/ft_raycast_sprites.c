/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_raycast_sprites.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 11:48:12 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 13:21:02 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int				ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

static void		ft_raycast_set_draw(t_cub *c)
{
	c->sprite_height = ft_abs((int)(c->res[1] / (c->transform.y)));
	c->draw_sprite_start.y = (-c->sprite_height / 2 +
	c->res[1] / 2);
	if (c->draw_sprite_start.y < 0)
		c->draw_sprite_start.y = 0;
	c->draw_sprite_end.y = (c->sprite_height / 2 + c->res[1] / 2);
	if (c->draw_sprite_end.y >= c->res[1])
		c->draw_sprite_end.y = c->res[1] - 1;
	c->sprite_width = ft_abs((int)(c->res[1] / (c->transform.y)));
	c->draw_sprite_start.x = -c->sprite_width / 2 + c->sprite_screen_x;
	if (c->draw_sprite_start.x < 0)
		c->draw_sprite_start.x = 0;
	c->draw_sprite_end.x = c->sprite_width / 2 + c->sprite_screen_x;
	if (c->draw_sprite_end.x >= c->res[0])
		c->draw_sprite_end.x = c->res[0] - 1;
}

void			ft_raycast_sprites(t_cub *c)
{
	int	i;

	i = 0;
	free(c->sprites);
	ft_set_sprites(c);
	ft_sort_sprites(c);
	while ((int)i < c->nb_sprites)
	{
		c->sprite.x = c->sprites[i].pos.x - c->pos.x;
		c->sprite.y = c->sprites[i].pos.y - c->pos.y;
		c->inv_det = 1.0 / ((c->plane.x * c->dir.y)
			- (c->dir.x * c->plane.y));
		c->transform.x = c->inv_det * ((c->dir.y * c->sprite.x)
			- (c->dir.x * c->sprite.y));
		c->transform.y = c->inv_det * ((-c->plane.y * c->sprite.x)
			+ (c->plane.x * c->sprite.y));
		c->sprite_screen_x = (int)((c->res[0] / 2) *
			(1 + c->transform.x / c->transform.y));
		ft_raycast_set_draw(c);
		ft_draw_sprite(c, i);
		i++;
	}
}
