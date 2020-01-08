/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 14:35:55 by tclaudel     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2020/01/07 14:16:28 by tclaudel    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2020/01/08 11:45:47 by tclaudel    ###    #+. /#+    ###.fr     */
>>>>>>> 8b52046
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
		c->dp_data[i * c->res[0] + x] = c->f;
		i++;
	}
}

void	ft_draw_ceiling(t_cub *c, int x)
{
	int	i;

	i = 0;
	while (i < c->draw_start)
	{
		c->dp_data[i * c->res[0] + x] = c->c;
		i++;
	}
}

void	ft_draw(t_cub *c, int x)
{
	int color;
	int	i;

	i = c->draw_start;
	if (c->side_hited == 1)
		color = 0xdddddd;
	else
		color = 0xffffff;
	while (i < c->draw_end)
	{
		c->dp_data[i * c->res[0] + x] = color;
		i++;
	}
	ft_draw_floor(c, x);
	ft_draw_ceiling(c, x);
}
