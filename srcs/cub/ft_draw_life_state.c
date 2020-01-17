/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_life_state.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 09:34:26 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 17:13:29 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_death(t_cub *c, int color)
{
	t_pos		img;
	t_vector	text;
	t_vector	ratio;

	ratio.x = (double)c->text[9].width / (double)c->res[0];
	ratio.y = (double)c->text[9].height / (double)c->res[1];
	img.x = 0;
	text.x = 0;
	while (img.x < c->res[0] - 1)
	{
		img.y = 0;
		text.y = 0;
		while (img.y < c->res[1])
		{
			color = c->text[9].img_data[(int)text.y * c->text[9].width +
				(int)text.x];
			c->dp.img_data[img.y * c->res[0] + img.x] = color;
			img.y++;
			text.y += ratio.y;
		}
		img.x++;
		text.x += ratio.x;
	}
}

void	ft_draw_victory(t_cub *c)
{
	t_pos		img;
	t_vector	text;
	t_vector	ratio;
	int			color;

	ratio.x = (double)c->text[10].width / (double)c->res[0];
	ratio.y = (double)c->text[10].height / (double)c->res[1];
	img.x = 0;
	text.x = 0;
	while (img.x < c->res[0] - 1)
	{
		img.y = 0;
		text.y = 0;
		while (img.y < c->res[1])
		{
			color = c->text[10].img_data[(int)text.y *
				c->text[10].width + (int)text.x];
			c->dp.img_data[img.y * c->res[0] + img.x] = color;
			img.y++;
			text.y += ratio.y;
		}
		img.x++;
		text.x += ratio.x;
	}
}
