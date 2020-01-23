/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 16:28:08 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 09:54:52 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_floor(t_cub *c, int x)
{
	int			i;
	t_color		color;
	double		darker;
	int			dist;

	color.color = c->f;
	i = c->res[1] - 1;
	while (i >= c->draw_end && i > 0)
	{
		dist = (i - c->res[1] / 2);
		darker = dist < RENDERDIST * 5 ? (double)dist / (RENDERDIST * 5) : 1.0;
		color.rgb.r *= darker;
		color.rgb.b *= darker;
		color.rgb.g *= darker;
		c->screen.img_data[i * c->res[0] + x] = color.color;
		i--;
	}
}

void	ft_draw_ceiling(t_cub *c, int x)
{
	int			i;
	t_color		color;

	i = 0;
	color.color = c->c;
	while (i < c->draw_start)
	{
		c->screen.img_data[i * c->res[0] + x] = color.color;
		i++;
	}
}

void	ft_draw_wall(t_cub *c, int x)
{
	int			i;
	int			d;
	t_color		color;
	double		darker;

	i = c->draw_start;
	while (i < c->draw_end)
	{
		d = i * 256 - c->res[1] * 128 + c->text[c->tex_nb].height * 128;
		c->tex_y = (int)c->text_pos & (d * c->text[c->tex_nb].height - 1);
		c->text_pos += c->text_step;
		color.color = c->text[c->tex_nb].img_data
			[c->tex_y * c->text[c->tex_nb].width + c->tex_x];
		darker = c->wall_dist > RENDERDIST ?
			0 : 1 - (c->wall_dist / RENDERDIST);
		color.rgb.r *= darker;
		color.rgb.b *= darker;
		color.rgb.g *= darker;
		c->screen.img_data[i * c->res[0] + x] = color.color;
		c->zbuffer[x] = c->wall_dist;
		i++;
	}
}

void	ft_draw(t_cub *c, int x)
{
	ft_draw_floor(c, x);
	ft_draw_ceiling(c, x);
	ft_draw_wall(c, x);
}
