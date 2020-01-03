/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lunch_window.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 14:21:22 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_close(t_cub *c)
{
	mlx_destroy_window(c->mlx_ptr, c->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_key_press(int keycode, t_cub *c)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(c->mlx_ptr, c->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		ft_lunch_window(t_cub *c)
{
	ft_printf("-->\tlunching window (%d * %d)\n", c->res[0], c->res[1]);
	// if ((c->mlx_ptr = mlx_init()) == NULL)
	// 	return (EXIT_FAILURE);
	// if ((c->mlx_win =
	// 	mlx_new_window(c->mlx_ptr, c->res[0], c->res[1], "c3D")) == NULL)
	// 	return (EXIT_FAILURE);
	// mlx_hook(c->mlx_win, 2, 0, &ft_key_press, c);
	// mlx_hook(c->mlx_win, 17, 0, &ft_close, c);
	ft_raycast(c);
	//mlx_loop(c->mlx_ptr);
	return (EXIT_SUCCESS);
}
