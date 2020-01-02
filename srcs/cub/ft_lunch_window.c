/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lunch_window.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 13:35:18 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_lunch_window(t_meta *meta)
{
	ft_printf("-->\tlunching window (%d * %d)\n", meta->cub->r[0], meta->cub->r[1]);
	if ((meta->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((meta->mlx_win =
		mlx_new_window(meta->mlx_ptr, meta->cub->r[0], meta->cub->r[1], "CUB3D")) == NULL)
		return (EXIT_FAILURE);
	// core function
	mlx_loop(meta->mlx_ptr);
	return (EXIT_SUCCESS);
}
