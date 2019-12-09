/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ea_convert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:05:34 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 18:23:09 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_ea_convert(const char **token, t_cube3d *cub)
{
	int		fd;

	ft_dprintf(1, "CATCHING EA TEXTURE\t| ");
	fd = open(token[1], O_RDONLY);
	if (fd < 0)
		ft_error("No such file or directory");
	cub->EA = ft_strdup(token[1]);
	ft_printfducul("path\t: %s\n", cub->EA);
}