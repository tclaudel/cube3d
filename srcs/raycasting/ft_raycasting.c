/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_raycasting.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 11:12:04 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 11:20:26 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

/*
**DDA mean Digital differential analyzer
*/

void	ft_set_raycast_values(t_cub *c, t_vector ray)
{
	c->square->x = (int)c->pos->x;
	c->square->y = (int)c->pos->y;
	c->delta_dist.x = fabs((double)1 / ray.x);
	c->delta_dist.y = fabs((double)1 / ray.y);
	if (ray.x < 0)
	{
		c->step->x = -1;
		c->side_dist.x = (c->pos->x - c->square->x) * c->delta_dist.x;
	}
	else
	{
		c->step->x = 1;
		c->side_dist.x = (c->square->x + 1.0 - c->pos->x) * c->delta_dist.x;
	}
	if (ray.y < 0)
	{
		c->step->y = -1;
		c->side_dist.y = (c->pos->y - c->square->y) * c->delta_dist.y;
	}
	else
	{
		c->step->y = 1;
		c->side_dist.y = (c->square->y + 1.0 - c->pos->y) * c->delta_dist.y;
	}
}

void	ft_perform_dda(t_cub *c, t_vector ray)
{
	c->hit = 0;
	c->side_hited = 0;
	ft_set_raycast_values(c, ray);
	while (c->hit == 0)
	{
		if (c->side_dist.x < c->side_dist.y)
		{
			c->side_dist.x += c->delta_dist.x;
			c->square->x += c->step->x;
			c->side_hited = 0;
		}
		else
		{
			c->side_dist.y += c->delta_dist.y;
			c->square->y += c->step->y;
			c->side_hited = 1;
		}
		if (c->map[c->square->y][c->square->x] == '1')
			c->hit = 1;
	}
}

void	ft_ray_text(t_cub *c)
{
	if (c->side_hited == 1)
	{
		dprintf(1, "\n[1] c->pos->y + c->wall * c->dir.y\n%f + %f * %f = ", c->pos->y, c->wall, c->dir.y);
		c->wall_pos = c->pos->y + c->wall * c->dir.y;
	}
	else
	{
		dprintf(1, "\n[0] c->pos->x + c->wall * c->dir.x\n%f + %f * %f = ", c->pos->x, c->wall, c->dir.x);
		c->wall_pos = c->pos->x + c->wall * c->dir.x;
	}
	dprintf(1, "%f\n", c->wall_pos);
	c->wall_pos -= (int)c->wall_pos;
	//dprintf(1, "c->wall_pos\t : %f\n", c->wall_pos);
	c->tex_x = (int)(c->wall_pos * (double)c->text[0].width);
	// dprintf(1, "tex_x\t: %d\n", c->tex_x);
	if (c->side_hited == 1 && c->dir.x > 0)
	{	
		c->tex_x = c->text[0].width - c->tex_x - 1;
	}
	if (c->side_hited == 0 && c->dir.y < 0)
	{
		c->tex_x = c->text[0].width - c->tex_x - 1;
	}
	c->text_step = 1.0 *  c->text[0].height / c->line_height;
	c->text_pos = (c->draw_start - c->res[1] / 2 + c->line_height / 2) * c->text_step;
}

int		ft_raycasting(t_cub *c)
{
	int			x;
	t_vector	ray;

	x = 0;
	while (x < c->res[0])
	{
		c->camera_x = 2 * x / (double)c->res[0] - 1;
		ray.x = c->dir.x + c->pla->x * c->camera_x;
		ray.y = c->dir.y + c->pla->y * c->camera_x;
		ft_perform_dda(c, ray);
		if (c->side_hited == 0)
			c->wall = (c->square->x - c->pos->x + (1 - c->step->x) / 2) / ray.x;
		else
			c->wall = (c->square->y - c->pos->y + (1 - c->step->y) / 2) / ray.y;
		c->line_height = (int)(c->res[1] / c->wall);
		c->draw_start = -c->line_height / 2 + c->res[1] / 2;
		if (c->draw_start < 0)
			c->draw_start = 0;
		c->draw_end = c->line_height / 2 + c->res[1] / 2;
		if (c->draw_start < 0)
			c->draw_end = 0;
		if (c->draw_end >= c->res[1])
			c->draw_end = c->res[1] - 1;
		ft_ray_text(c);
		ft_draw(c, x);
		x++;
	}
	return (1);
}
