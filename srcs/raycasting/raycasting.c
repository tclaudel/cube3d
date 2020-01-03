/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 11:12:04 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 14:35:14 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

/*
**DDA mean Digital differential analyzer
*/

void	ft_set_raycast_values(t_cub *c, t_vector ray)
{
	c->square.x = (int)c->pos->x;
	c->square.y = (int)c->pos->y;
	c->delta_dist.x = fabs(1 / ray.x);
	c->delta_dist.y = fabs(1 / ray.y);
	c->wall_hit = 0;
	if (ray.x < 0)
	{
		c->step.x = -1;
		c->side_dist.x = (c->pos->x - c->square.x) * c->delta_dist.x;
	}
	else
	{
		c->step.x = 1;
		c->side_dist.x = (c->square.x + 1 - c->pos->x) * c->delta_dist.x;
	}
	if (ray.y < 0)
	{
		c->step.y = -1;
		c->side_dist.y = (c->pos->y - c->square.y) * c->delta_dist.y;
	}
	else
	{
		c->step.y = 1;
		c->side_dist.y = (c->square.y + 1 - c->pos->y) * c->delta_dist.y;
	}
}

void	ft_perform_dda(t_cub *c, t_vector ray)
{
	ft_set_raycast_values(c, ray);
	while (c->wall_hit == 0)
	{
		if (c->side_dist.x < c->side_dist.y)
		{
			c->side_dist.x += c->delta_dist.x;
			c->square.x += c->step.x;
			c->wall_side_hited = 0;
		}
		else
		{
			c->side_dist.y += c->delta_dist.y;
			c->square.y += c->step.y;
			c->wall_side_hited = 1;
		}
		if (c->map[c->square.x][c->square.y] == '1')
		{
			c->wall_hit = 1;
		}
	}
}

int		ft_raycast(t_cub *c)
{
	int			i;
	t_vector	ray;

	i = 0;
	while (i < c->res[0])
	{
		c->camera_x = 2 * i / c->res[0] - 1;
		ray.x = c->pos->x + c->plane.x * c->camera_x;
		ray.y = c->pos->y + c->plane.y * c->camera_x;
		ft_set_raycast_values(c, ray);
		ft_perform_dda(c, ray);
		i++;
	}
	return (1);
}
