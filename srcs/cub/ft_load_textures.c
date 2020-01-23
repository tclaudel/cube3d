/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_load_textures.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 12:49:57 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 09:58:26 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_load_nose_textures(t_cub *c)
{
	if (!(c->text[0].img =
		mlx_xpm_file_to_image(c->mlx_ptr, c->no,
		&c->text[0].width, &c->text[0].height)))
		return (EXIT_FAILURE);
	if (!(c->text[0].img_data =
		(int *)mlx_get_data_addr(c->text[0].img, &c->text[0].bpp,
		&c->text[0].size_line, &c->text[0].endian)))
		return (EXIT_FAILURE);
	if (!(c->text[1].img =
		mlx_xpm_file_to_image(c->mlx_ptr, c->so,
		&c->text[1].width, &c->text[1].height)))
		return (EXIT_FAILURE);
	if (!(c->text[1].img_data =
		(int *)mlx_get_data_addr(c->text[1].img, &c->text[1].bpp,
		&c->text[1].size_line, &c->text[1].endian)))
		return (EXIT_FAILURE);
	return (0);
}

static int	ft_load_eawe_textures(t_cub *c)
{
	if (!(c->text[2].img =
		mlx_xpm_file_to_image(c->mlx_ptr, c->ea, &c->text[2].width,
		&c->text[2].height)))
		return (EXIT_FAILURE);
	if (!(c->text[2].img_data =
		(int *)mlx_get_data_addr(c->text[2].img, &c->text[2].bpp,
		&c->text[2].size_line, &c->text[2].endian)))
		return (EXIT_FAILURE);
	if (!(c->text[3].img =
		mlx_xpm_file_to_image(c->mlx_ptr, c->we, &c->text[3].width,
		&c->text[3].height)))
		return (EXIT_FAILURE);
	if (!(c->text[3].img_data =
		(int *)mlx_get_data_addr(c->text[3].img, &c->text[3].bpp,
		&c->text[3].size_line, &c->text[3].endian)))
		return (EXIT_FAILURE);
	return (0);
}

static int	ft_load_sprites_textures(t_cub *c, int i, char *path)
{
	while (i < 9)
	{
		if (i == 5)
			path = c->s;
		else if (i == 6)
			path = "./textures/heal.xpm";
		else if (i == 7)
			path = "./textures/mine.xpm";
		else if (i == 8)
			path = "./textures/ruby.xpm";
		if (!(c->text[i].img =
			mlx_xpm_file_to_image(c->mlx_ptr, path, &c->text[i].width,
			&c->text[i].height)))
			return (EXIT_FAILURE);
		if (!(c->text[i].img_data =
			(int *)mlx_get_data_addr(c->text[i].img, &c->text[i].bpp,
			&c->text[i].size_line, &c->text[i].endian)))
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

static int	ft_load_hud(t_cub *c)
{
	char	*path;

	path = "./textures/hud480.xpm";
	if (!(c->text[4].img =
		mlx_xpm_file_to_image(c->mlx_ptr, path, &c->text[4].width,
		&c->text[4].height)))
		return (EXIT_FAILURE);
	if (!(c->text[4].img_data =
		(int *)mlx_get_data_addr(c->text[4].img, &c->text[4].bpp,
		&c->text[4].size_line, &c->text[4].endian)))
		return (EXIT_FAILURE);
	return (0);
}

void		ft_load_textures(t_cub *c)
{
	if (ft_load_nose_textures(c))
		ft_error("Failed to load textures");
	if (ft_load_eawe_textures(c))
		ft_error("Failed to load textures");
	if (ft_load_sprites_textures(c, 5, NULL))
		ft_error("Failed to load textures");
	if (ft_load_hud(c))
		ft_error("Failed to load textures");
}
