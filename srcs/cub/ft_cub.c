/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 12:33:03 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 17:03:42 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void			ft_display_map(t_cub *c)
{
	size_t	i;

	i = 0;
	c->tabmap[(int)c->pos.x][(int)c->pos.y] = '#';
	printf("\nMAP :\n\n");
	while (i < c->map_height)
	{
		ft_printf("%s\n", c->tabmap[i]);
		i++;
	}
}

static int		main_loop(t_cub *c)
{
	if (c->move)
		ft_move(c);
	if (c->rot)
		ft_rot(c);
	ft_raycast(c);
	mlx_put_image_to_window(c->mlx_ptr, c->mlx_win, c->dp.img, 0, 0);
	return (0);
}

int				ft_cub(t_cub *c)
{
	if ((c->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	init_player(c);
	ft_display_map(c);
	ft_load_textures(c);
	ft_launch_window(c);
	mlx_hook(c->mlx_win, 2, 0, &ft_key_press, c);
	mlx_hook(c->mlx_win, 3, 0, &ft_key_release, c);
	mlx_hook(c->mlx_win, 17, 0, &ft_close, c);
	mlx_loop_hook(c->mlx_ptr, &main_loop, c);
	mlx_loop(c->mlx_ptr);
	return (1);
}
