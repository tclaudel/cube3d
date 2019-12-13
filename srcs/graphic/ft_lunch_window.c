/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lunch_window.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 17:48:34 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_lunch_window(t_cube3d *cub)
{
	data_t	data;

	ft_printf("-->\tlunching window (%d * %d)\n", cub->r[0], cub->r[1]);
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win =
		mlx_new_window(data.mlx_ptr, cub->r[0], cub->r[1], "DU CUL")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
