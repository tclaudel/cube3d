/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lunch_window.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 17:35:14 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_close(t_cube3d *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_key_press(int keycode, t_cube3d *cub)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		ft_raycast(t_meta *meta)
{
	int			i;
	t_vector	ray;

	i = 0;
	while(i < meta->cub->r[0])
	{
		meta->cub->camera_x = 2 * i / meta->cub->r[0] - 1;
		ray->x = 
		i++;
	}
}

int		ft_lunch_window(t_meta *meta)
{
	t_cube3d	*cub;

	cub = meta->cub;
	ft_printf("-->\tlunching window (%d * %d)\n", cub->r[0], cub->r[1]);
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((cub->mlx_win =
		mlx_new_window(cub->mlx_ptr, cub->r[0], cub->r[1], "CUB3D")) == NULL)
		return (EXIT_FAILURE);
	mlx_hook(cub->mlx_win, 2, 0, &ft_key_press, cub);
	mlx_hook(cub->mlx_win, 17, 0, &ft_close, cub);
	ft_raycast(meta);
	mlx_loop(cub->mlx_ptr);
	return (EXIT_SUCCESS);
}
