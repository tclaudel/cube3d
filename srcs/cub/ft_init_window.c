/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_window.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 16:06:01 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_launch_window(t_cub *c)
{
	ft_printf("-->\tlaunching window (%d * %d)\n", c->res[0], c->res[1]);
	if (!(c->dp.img = mlx_new_image(c->mlx_ptr, c->res[0], c->res[1])))
		return (EXIT_FAILURE);
	if (!(c->dp.img_data =
		(int *)mlx_get_data_addr(c->dp.img, &c->dp.bpp,
		&c->dp.size_line, &c->dp.endian)))
		return (EXIT_FAILURE);
	if ((c->mlx_win =
		mlx_new_window(c->mlx_ptr, c->res[0], c->res[1], "CUB 3D")) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
