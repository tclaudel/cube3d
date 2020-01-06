/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 14:35:55 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 15:33:11 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw(t_cub *c, int x)
{
	while (c->draw_start < c->draw_end)
	{
		mlx_pixel_put(c->mlx_ptr, c->mlx_win, x, c->draw_start, 240);
		c->draw_start++;
	}
}