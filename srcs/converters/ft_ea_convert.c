/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ea_convert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:05:34 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 11:59:36 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_ea_convert(const char **token, t_cube3d *cub)
{
	int		fd;
	char	*buf;

	buf = NULL;
	ft_dprintf(1, "CATCHING EA TEXTURE\t| ");
	if(token[2])
		ft_error("too many arguments for this parameter");
	fd = open(token[1], O_RDONLY);
	if (fd < 0)
		ft_error("No such file or directory");
	if (read(fd, buf, 0) != 0)
		ft_error("Not a valid file");
	close(fd);
	cub->EA = ft_strdup(token[1]);
	ft_printfducul("path\t: %s\n", cub->EA);
}