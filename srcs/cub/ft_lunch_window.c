/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lunch_window.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 09:24:27 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		ft_raycast(t_cub *cub)
{
	int			i;
	//t_vector	ray;

	i = 0;
	while(i < cub->res[0])
	{
		cub->camera_x = 2 * i / cub->res[0] - 1;
		//ray->x = cub->player_pos_x;
		i++;
	}
	return (1);
}

int		ft_lunch_window(t_cub *cub)
{
	ft_printf("-->\tlunching window (%d * %d)\n", cub->res[0], cub->res[1]);
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((cub->mlx_win =
		mlx_new_window(cub->mlx_ptr, cub->res[0], cub->res[1], "CUB3D")) == NULL)
		return (EXIT_FAILURE);
	mlx_hook(cub->mlx_win, 2, 0, &ft_key_press, cub);
	mlx_hook(cub->mlx_win, 17, 0, &ft_close, cub);
	ft_raycast(cub);
	mlx_loop(cub->mlx_ptr);
	return (EXIT_SUCCESS);
}
