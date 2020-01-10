/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 16:28:08 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 10:09:49 by tclaudel    ###    #+. /#+    ###.fr     */
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

	if (c->side)
		c->tex_nb = c->ray_dir.y < 0 ? 2 : 3;
	else
		c->tex_nb = c->ray_dir.x < 0 ? 0 : 1;
	i = c->draw_start;
	while (i < c->draw_end)
	{
		c->tex_y = (int)c->text_pos & (c->text[c->tex_nb].height - 1);
		c->text_pos += c->text_step;
		color = c->text[c->tex_nb].img_data
			[c->tex_y * c->text[c->tex_nb].width + c->tex_x];
		c->dp.img_data[i * c->res[0] + x] = color;
		i++;
	}
	ft_draw_floor(c, x);
	ft_draw_ceiling(c, x);
}
