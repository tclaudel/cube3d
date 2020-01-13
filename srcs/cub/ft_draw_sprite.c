/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 14:42:56 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 13:05:12 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_sprite_on_display(t_cub *c)
{
	int		color;
	int		d;
	int		y;

	y = c->draw_sprite_start.y - 1;
	while (++y < c->draw_sprite_end.y)
	{
		d = y * 256 - c->res[1] * 128 + c->sprite_height * 128;
		c->tex_y = ((d * c->text[4].height) / c->sprite_height) / 256;
		color = c->text[4].img_data[c->tex_y * c->text[4].width + c->tex_x];
		if ((color & 0xffffff) != 0)
			c->dp.img_data[y * c->res[0] + c->stripe] = color;
	}
}

void	ft_draw_sprite(t_cub *c)
{
	c->stripe = c->draw_sprite_start.x;
	while (c->stripe < c->draw_sprite_end.x)
	{
		c->tex_x = (int)((256 * (c->stripe -
		(-c->sprite_width / 2 + c->sprite_screen_x)) *
		c->text[4].width / c->sprite_width) / 256);
		if (c->transform.y > 0 && c->stripe > 0 && c->stripe < c->res[0] &&
			c->transform.y < c->zbuffer[c->stripe])
			ft_draw_sprite_on_display(c);
		c->stripe++;
	}
}
