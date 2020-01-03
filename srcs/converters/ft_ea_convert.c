/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ea_convert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:05:34 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 08:47:07 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_ea_convert(char **token, t_cub *cub)
{
	int		fd;
	char	*buf;

	buf = NULL;
	if (cub->ea)
		ft_error("can't redefine parameter");
	ft_dprintf(1, "ea texture path\t: ");
	if (token[2])
		ft_error("too many arguments for this parameter");
	fd = open(token[1], O_RDONLY);
	if (fd < 0)
		ft_error("No such file or directory");
	if (read(fd, buf, 0) != 0)
		ft_error("Not a valid file");
	close(fd);
	cub->ea = ft_strdup(token[1]);
	ft_printf("%s\n", cub->ea);
}
