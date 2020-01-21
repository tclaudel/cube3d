/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 14:42:56 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 17:46:33 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_sprite_on_display(t_cub *c, int i)
{
	t_color		color;
	int			d;
	int			y;
	double		darker;

	y = c->draw_sprite_start.y - 1;
	while (++y < c->draw_sprite_end.y)
	{
		d = y * 256 - c->res[1] * 128 + c->sprite_height * 128;
		c->tex_y = ((d * c->text[5 + c->sprites[i].type].height) /
			c->sprite_height) / 256;
		color.color =
			c->text[5 + c->sprites[i].type].img_data[c->tex_y * c->text[5 +
			c->sprites[i].type].width + c->tex_x];
		darker = c->transform.y > RENDERDIST ?
			0 : 1 - (c->transform.y / RENDERDIST);
		color.rgb.r *= darker;
		color.rgb.b *= darker;
		color.rgb.g *= darker;
		if ((color.color & 0xffffff) != 0)
			c->dp.img_data[y * c->res[0] + c->stripe] = color.color;
	}
}

void	ft_draw_sprite(t_cub *c, int i)
{
	c->stripe = c->draw_sprite_start.x;
	while (c->stripe < c->draw_sprite_end.x)
	{
		c->tex_x = (int)((256 * (c->stripe -
		(-c->sprite_width / 2 + c->sprite_screen_x)) *
		c->text[5 + c->sprites[i].type].width / c->sprite_width) / 256);
		if (c->transform.y > 0 && c->stripe > 0 && c->stripe < c->res[0] &&
			c->transform.y < c->zbuffer[c->stripe])
			ft_draw_sprite_on_display(c, i);
		c->stripe++;
	}
}
