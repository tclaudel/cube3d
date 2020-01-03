/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 11:12:04 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 12:03:08 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_set_raycast_values(t_cub *c, t_vector ray)
{
	c->square.x = (int)c->pos->x;
	c->square.y = (int)c->pos->y;
	c->delta_dist.x = fabs(1 / ray.x);
	c->delta_dist.y = fabs(1 / ray.y);
	if (ray.x < 0)
	{
		c->step.x = -1;
		c->side_dist.x = (c->pos->x - c->start->x) * c->delta_dist.x;
	}
	else
	{
		c->step.x = 1;
		c->side_dist.x = (c->start->x + 1 - c->pos->x) * c->delta_dist.x;
	}
	if (ray.y < 0)
	{
		c->step.y = -1;
		c->side_dist.y = (c->pos->y - c->start->y) * c->delta_dist.y;
	}
	else
	{
		c->step.x = 1;
		c->side_dist.y = (c->start->y + 1 - c->pos->y) * c->delta_dist.y;
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
		i++;
	}
	return (1);
}
