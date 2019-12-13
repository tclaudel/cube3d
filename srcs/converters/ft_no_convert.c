/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_no_convert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 15:16:01 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 10:03:29 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_no_convert(char **token, t_cube3d *cub)
{
	int		fd;
	char	*buf;

	buf = NULL;
	if (cub->no)
		ft_error("can't redefine parameter");
	ft_dprintf(1, "no texture path\t: ");
	if (token[2])
		ft_error("too many arguments for this parameter");
	fd = open(token[1], O_RDONLY);
	if (fd < 0)
		ft_error("No such file or directory");
	if (read(fd, buf, 0) != 0)
		ft_error("Not a valid file");
	close(fd);
	cub->no = ft_strdup(token[1]);
	ft_printf("%s\n", cub->no);
}
