/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_raycast.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 15:26:00 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 15:15:29 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_search_walls(t_cub *c)
{
	c->map.x = (int)(c->pos.x);
	c->map.y = (int)(c->pos.y);
	c->delta_dist.x = fabs(1 / c->ray_dir.x);
	c->delta_dist.y = fabs(1 / c->ray_dir.y);
	c->hit = 0;
	if (c->ray_dir.x < 0)
	{
		c->step.x = -1;
		c->side_dist.x = (c->pos.x - c->map.x) * c->delta_dist.x;
	}
	else
	{
		c->step.x = 1;
		c->side_dist.x = (c->map.x + 1.0 - c->pos.x) * c->delta_dist.x;
	}
	if (c->ray_dir.y < 0)
	{
		c->step.y = -1;
		c->side_dist.y = (c->pos.y - c->map.y) * c->delta_dist.y;
	}
	else
	{
		c->step.y = 1;
		c->side_dist.y = (c->map.y + 1.0 - c->pos.y) * c->delta_dist.y;
	}
}

static void		ft_perform_dda(t_cub *c)
{
	while (c->hit == 0)
	{
		if (c->side_dist.x < c->side_dist.y)
		{
			c->side_dist.x += c->delta_dist.x;
			c->map.x += c->step.x;
			c->side = 0;
		}
		else
		{
			c->side_dist.y += c->delta_dist.y;
			c->map.y += c->step.y;
			c->side = 1;
		}
		if (c->tabmap[c->map.x][c->map.y] == '1')
			c->hit = 1;
	}
}

static void		ft_setup_draw(t_cub *c)
{
	if (c->side == 0)
		c->wall_dist =
			(c->map.x - c->pos.x + (1 - c->step.x) / 2) / c->ray_dir.x;
	else
		c->wall_dist =
			(c->map.y - c->pos.y + (1 - c->step.y) / 2) / c->ray_dir.y;
	c->line_height = (int)(c->res[1] / c->wall_dist);
	c->draw_start = -c->line_height / 2 + c->res[1] / 2;
	if (c->draw_start < 0)
		c->draw_start = 0;
	c->draw_end = c->line_height / 2 + c->res[1] / 2;
	if (c->draw_end > c->res[1])
		c->draw_end = c->res[1] - 1;
}

static void		ft_raycast_textures(t_cub *c)
{
	if (c->side)
		c->tex_nb = c->ray_dir.y < 0 ? 2 : 3;
	else
		c->tex_nb = c->ray_dir.x < 0 ? 1 : 0;
	if (c->side == 0)
		c->wall_pos = c->pos.y + c->wall_dist * c->ray_dir.y;
	else
		c->wall_pos = c->pos.x + c->wall_dist * c->ray_dir.x;
	c->wall_pos -= (int)c->wall_pos;
	c->tex_x = (int)(c->wall_pos * (double)(c->text[c->tex_nb].width));
	if (c->side == 0 && c->ray_dir.x > 0)
		c->tex_x = c->text[c->tex_nb].width - c->tex_x - 1;
	if (c->side == 1 && c->ray_dir.y < 0)
		c->tex_x = c->text[c->tex_nb].width - c->tex_x - 1;
	c->text_step = 1.0 * c->text[c->tex_nb].height / c->line_height;
	c->text_pos =
		(c->draw_start - c->res[1] / 2 + c->line_height / 2) * c->text_step;
}

void			ft_raycast(t_cub *c)
{
	int		x;

	x = 0;
	while (x < c->res[0])
	{
		c->camera_x = 2 * x / (double)c->res[0] - 1;
		c->ray_dir.x = c->dir.x + c->plane.x * c->camera_x;
		c->ray_dir.y = c->dir.y + c->plane.y * c->camera_x;
		ft_search_walls(c);
		ft_perform_dda(c);
		ft_setup_draw(c);
		ft_raycast_textures(c);
		ft_draw(c, x);
		x++;
	}
	ft_raycast_sprites(c);
	if(c->text[5].img_data)
		ft_draw_hud(c);
	if(c->res[0] >= 720 && c->res[1] >= 480)
		ft_draw_hud(c);
	if(c->res[0] >= 720 && c->res[1] >= 480)
		ft_draw_lifebar(c);
	if(c->res[0] >= 720 && c->res[1] >= 480)
		ft_draw_success(c);
}
