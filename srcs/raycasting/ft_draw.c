/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 14:35:55 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 09:07:32 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_floor(t_cub *c, int x)
{
	int	i;

	i = c->draw_end;
	while (i < c->res[1])
	{
		c->dp.img_data[i * c->res[0] + x] = c->f;
		i++;
	}
}

void	ft_draw_ceiling(t_cub *c, int x)
{
	int	i;

	i = 0;
	while (i < c->draw_start)
	{
		c->dp.img_data[i * c->res[0] + x] = c->c;
		i++;
	}
}

void	ft_draw(t_cub *c, int x)
{
	int color;
	int	i;

	i = c->draw_start;
	while (i < c->draw_end)
	{
		c->tex_y = (int)c->text_pos & (c->text[0].height -1);
		c->text_pos += c->text_step;
		color = c->text[0].img_data[c->tex_y * c->text[0].width + c->tex_x];
		c->dp.img_data[i * c->res[0] + x] = color;
		i++;
	}
	ft_draw_floor(c, x);
	ft_draw_ceiling(c, x);
}
