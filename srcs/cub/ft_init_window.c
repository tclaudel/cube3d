/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_window.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:05:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 10:01:19 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_load_life_screen(t_cub *c)
{
	if (!(c->text[9].img =
		mlx_xpm_file_to_image(c->mlx_ptr, "./textures/death.xpm",
		&c->text[9].width, &c->text[9].height)))
		return (EXIT_FAILURE);
	if (!(c->text[9].img_data =
		(int *)mlx_get_data_addr(c->text[9].img, &c->text[9].bpp,
		&c->text[9].size_line, &c->text[9].endian)))
		return (EXIT_FAILURE);
	if (!(c->text[10].img =
		mlx_xpm_file_to_image(c->mlx_ptr, "./textures/win.xpm",
		&c->text[10].width, &c->text[10].height)))
		return (EXIT_FAILURE);
	if (!(c->text[10].img_data =
		(int *)mlx_get_data_addr(c->text[10].img, &c->text[10].bpp,
		&c->text[10].size_line, &c->text[10].endian)))
		return (EXIT_FAILURE);
	return (0);
}

int			ft_launch_window(t_cub *c)
{
	ft_load_textures(c);
	if (ft_load_life_screen(c))
		ft_error("Failed to load textures");
	if (!(c->screen.img = mlx_new_image(c->mlx_ptr, c->res[0], c->res[1])))
		return (EXIT_FAILURE);
	if (!(c->screen.img_data =
		(int *)mlx_get_data_addr(c->screen.img, &c->screen.bpp,
		&c->screen.size_line, &c->screen.endian)))
		return (EXIT_FAILURE);
	if ((c->mlx_win =
		mlx_new_window(c->mlx_ptr, c->res[0], c->res[1], "cub3D")) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
