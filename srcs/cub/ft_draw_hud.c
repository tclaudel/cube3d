/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_hud.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 16:32:32 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 09:04:19 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_hud(t_cub *c)
{
	int		x;
	int		y;
	int		color;
	t_pos	tex;

	c->text_step = 1.0 * c->text[c->tex_nb].height / c->res[1];
	x = (c->res[0] - c->text[4].width) / 2;
	tex.x = 0;
	while (x < c->res[0] && tex.x < c->text[4].width)
	{
		y = 0;
		tex.y = 0;
		while (y < (c->res[0] / 2) && tex.y < c->text[4].height)
		{
			color = c->text[4].img_data[tex.y * c->text[4].width + tex.x];
			if ((color & 0xffffff) != 0)
				c->screen.img_data[y * c->res[0] + x] = color;
			y++;
			tex.y++;
		}
		x++;
		tex.x++;
	}
}
