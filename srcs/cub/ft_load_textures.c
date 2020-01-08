/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_load_textures.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 13:49:57 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 15:49:59 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_load_nose_textures(t_cub *c)
{
	if (!(c->no_text.img= mlx_xpm_file_to_image(c->mlx_win, c->no,
		&c->no_text.width, &c->no_text.height)))
		return (EXIT_FAILURE);
	if (!(c->no_text.img_data =
		(int *)mlx_get_data_addr(c->no_text.img, &c->no_text.bpp,
		&c->no_text.size_line, &c->no_text.endian)))
		return (EXIT_FAILURE);
	if (!(c->so_text.img=
		mlx_xpm_file_to_image(c->mlx_win, c->so,
		&c->so_text.width, &c->so_text.height)))
		return (EXIT_FAILURE);
	if (!(c->so_text.img_data =
		(int *)mlx_get_data_addr(c->so_text.img, &c->so_text.bpp,
		&c->so_text.size_line, &c->so_text.endian)))
		return (EXIT_FAILURE);
	return (0);
}

static int	ft_load_weea_textures(t_cub *c)
{
	if (!(c->we_text.img=
		mlx_xpm_file_to_image(c->mlx_win, c->we, &c->we_text.width,
		&c->we_text.height)))
		return (EXIT_FAILURE);
	if (!(c->we_text.img_data =
		(int *)mlx_get_data_addr(c->we_text.img, &c->we_text.bpp,
		&c->we_text.size_line, &c->we_text.endian)))
		return (EXIT_FAILURE);
	if (!(c->ea_text.img=
		mlx_xpm_file_to_image(c->mlx_win, c->ea, &c->ea_text.width,
		&c->ea_text.height)))
		return (EXIT_FAILURE);
	if (!(c->ea_text.img_data =
		(int *)mlx_get_data_addr(c->ea_text.img, &c->ea_text.bpp,
		&c->ea_text.size_line, &c->ea_text.endian)))
		return (EXIT_FAILURE);
	return (0);
}

void		ft_load_textures(t_cub *c)
{
	ft_load_nose_textures(c);
	ft_load_weea_textures(c);
}