/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_raycasting.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 11:12:04 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 11:04:19 by tclaudel    ###    #+. /#+    ###.fr     */
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

int		ft_raycasting(t_cub *c)
{
	int			x;
	t_vector	ray;

	x = 0;
	while (x < c->res[0])
	{
		c->camera_x = 2 * x / (double)c->res[0] - 1;
		ray.x = c->dir.x + c->plane->x * c->camera_x;
		ray.y = c->dir.y + c->plane->y * c->camera_x;
		ft_perform_dda(c, ray);
		if (c->side_hited == 0)
			c->wall = (c->square->x - c->pos->x + (1 - c->step->x) / 2) / ray.x;
		else
			c->wall = (c->square->y - c->pos->y + (1 - c->step->y) / 2) / ray.y;
		//printf("\ncamera_x\tx : %f\nplane\t\tx : %f\ty : %f\nsquare\t\tx : %d\t\ty : %d\nray\t\tx : %f\ty : %f\ndir\t\tx : %f\ty : %f\nwall\t\t  : %f\n", c->camera_x, c->plane->x, c->plane->y, c->square->x, c->square->y,ray.x, ray.y, c->dir.x, c->dir.y, c->wall);
		c->line_height = (int)(c->res[1] / c->wall);
		//printf("line h\t\t  : %d\n\n", c->line_height);
		c->draw_start = -c->line_height / 2 + c->res[1] / 2;
		if (c->draw_start < 0)
			c->draw_start = 0;
		c->draw_end = c->line_height / 2 + c->res[1] / 2;
		if(c->draw_end >= c->res[1])
			c->draw_end = c->res[1] - 1;
		//printf("start\t: %d end\t: %d\n", c->draw_start, c->draw_end);
		ft_draw(c, x);
		x++;
	}
	return (1);
}
