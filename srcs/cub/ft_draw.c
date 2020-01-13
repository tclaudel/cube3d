/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 16:28:08 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 17:51:36 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_floor(t_cub *c, int x)
{
	int			i;

	i = ft_abs(c->draw_end);
	while (i < c->res[1] - 1)
	{
		c->dp.img_data[i * c->res[0] + x] = c->f;
		i++;
	}
}

void	ft_draw_ceiling(t_cub *c, int x)
{
	int			i;

	i = 0;
	while (i < c->draw_start)
	{
		c->dp.img_data[i * c->res[0] + x] = c->c;
		i++;
	}
}

void	ft_draw_wall(t_cub *c, int x)
{
	int			i;
	t_color		color;
	double		darker;

	i = c->draw_start;
	while (i < c->draw_end)
	{
		c->tex_y = (int)c->text_pos & (c->text[c->tex_nb].height - 1);
		c->text_pos += c->text_step;
		color.color = c->text[c->tex_nb].img_data
			[c->tex_y * c->text[c->tex_nb].width + c->tex_x];
		darker = c->wall_dist > RENDERDIST ?
			0 : 1 - (c->wall_dist / RENDERDIST);
		color.rgb.r *= darker;
		color.rgb.b *= darker;
		color.rgb.g *= darker;
		c->dp.img_data[i * c->res[0] + x] = color.color;
		c->zbuffer[x] = c->wall_dist;
		i++;
	}
}

// void	ft_draw_crosshair(t_cub *c, int x)
// {
// 	int		i;

// 	i = c->res[1] / 2 + 10;
// 	if (x > c->res[0] && x < c->res[0] / 2)
// 	{}	while (i < c->res[1] / 2 - 10)
// 		{
// 			c->dp.img_data[c->res[1] * c->res[0] + x] = 255;
// 			i++;
// 		}
// 	}
// }

void	ft_draw(t_cub *c, int x)
{
	if (c->side)
		c->tex_nb = c->ray_dir.y < 0 ? 2 : 3;
	else
		c->tex_nb = c->ray_dir.x < 0 ? 0 : 1;
	ft_draw_wall(c, x);
	ft_draw_floor(c, x);
	ft_draw_ceiling(c, x);
	//ft_draw_crosshair(c,x);
}
