/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lunch_window.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 13:49:12 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_lunch_window(t_cube3d *cub)
{
	ft_printf("-->\tlunching window (%d * %d)\n", cub->r[0], cub->r[1]);
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((cub->mlx_win =
		mlx_new_window(cub->mlx_ptr, cub->r[0], cub->r[1], "CUB3D")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop(cub->mlx_ptr);
	return (EXIT_SUCCESS);
}
