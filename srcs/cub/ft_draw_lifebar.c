/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_lifebar.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 10:59:30 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 16:58:28 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_lifebar(t_cub *c)
{
	int		x;
	int		y;

	x = 0;
	while (x < c->res[0] / 15)
	{
		y = c->res[1] - 1;
		while (y > 0)
		{
			if ((c->life != 0 && x > c->res[0] / 80 &&
			x < c->res[0] / 15 - c->res[0] / 80) &&
			(y > (int)((double)c->res[1] *
			(1 - (double)c->life / (double)c->maxlife))))
				c->dp.img_data[y * c->res[0] + x] = 0xff0000;
			else if (x < c->res[0] / 15)
				c->dp.img_data[y * c->res[0] + x] = 0x000000;
			y--;
		}
		x++;
	}
}

void	ft_draw_success(t_cub *c)
{
	int		x;
	int		y;

	x = c->res[0] - c->res[0] / 15;
	while (x < c->res[0])
	{
		y = c->res[1] - 1;
		while (y > 0)
		{
			if ((x > c->res[0] - c->res[0] / 15 + c->res[0] / 80) &&
				y > (int)(c->res[1] *
				(1 - (double)c->collect / (double)(c->max_collect))) &&
				x < c->res[0] - c->res[0] / 80)
				c->dp.img_data[y * c->res[0] + x] = 0xffff63;
			else if (x > c->res[0] - c->res[0] / 15)
				c->dp.img_data[y * c->res[0] + x] = 0x000000;
			y--;
		}
		x++;
	}
}
