/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:25:21 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 14:29:03 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_print_position(t_cub *c)
{
	size_t i;

	i = 0;
	ft_printf("\nMAP :\n\n");
	c->map[(int)c->pos->y][(int)c->pos->x] = (char)219;
	while (i < c->map_height)
	{
		ft_printf("%s\n", c->map[i]);
		i++;
	}
}

void	ft_move(t_cub *c)
{
	if (c->flag == 'm')
	{
		ft_print_position(c);
	}
	if (c->move == 'W')
	{
		c->pos->x += c->dir.x * MOVSPEED;
		if (c->map[(int)c->pos->y][(int)c->pos->x] == '1')
			c->pos->x -= c->dir.x * MOVSPEED;
		c->pos->y += c->dir.y * MOVSPEED;
		if (c->map[(int)c->pos->y][(int)c->pos->x] == '1')
			c->pos->y -= c->dir.y * MOVSPEED;
	}
	else if (c->move == 'S')
	{
		c->pos->x -= c->dir.x * MOVSPEED;
		if (c->map[(int)c->pos->y][(int)c->pos->x] == '1')
			c->pos->x += c->dir.x * MOVSPEED;
		c->pos->y -= c->dir.y * MOVSPEED;
		if (c->map[(int)c->pos->y][(int)c->pos->x] == '1')
			c->pos->y += c->dir.y * MOVSPEED;
	}
}

void	ft_rot(t_cub *c)
{
	c->old_dir.x = c->dir.x;
	c->old_pla.x = c->pla->x;
	if (c->rot == 'A')
	{
		c->dir.x = c->dir.x * cos(-ROTSPEED) - c->dir.y * sin(-ROTSPEED);
		c->dir.y = c->old_dir.x * sin(-ROTSPEED) + c->dir.y * cos(-ROTSPEED);
		c->pla->x = c->pla->x * cos(-ROTSPEED) - c->pla->y * sin(-ROTSPEED);
		c->pla->y = c->old_pla.x * sin(-ROTSPEED) + c->pla->y * cos(-ROTSPEED);
	}
	else if (c->rot == 'D')
	{
		c->dir.x = c->dir.x * cos(ROTSPEED) - c->dir.y * sin(ROTSPEED);
		c->dir.y = c->old_dir.x * sin(ROTSPEED) + c->dir.y * cos(ROTSPEED);
		c->pla->x = c->pla->x * cos(ROTSPEED) - c->pla->y * sin(ROTSPEED);
		c->pla->y = c->old_pla.x * sin(ROTSPEED) + c->pla->y * cos(ROTSPEED);
	}
}

int		main_loop(t_cub *c)
{
	if (c->move)
		ft_move(c);
	if (c->rot)
		ft_rot(c);
	printf("c->mp->x\t: %d\nc->mp->y\t: %d\n", c->mp->x, c->mp->y);
	ft_raycasting(c);
	mlx_put_image_to_window(c->mlx_ptr, c->mlx_win, c->dp.img, 0, 0);
	return (0);
}
