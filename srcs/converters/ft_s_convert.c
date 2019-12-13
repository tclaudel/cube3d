/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_s_convert.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 17:13:43 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 10:03:32 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_s_convert(char **token, t_cube3d *cub)
{
	int		fd;
	char	*buf;

	if (cub->s)
		ft_error("can't redefine parameter");
	buf = NULL;
	ft_dprintf(1, "s  texture\t: ");
	if (token[2])
		ft_error("too many arguments for this parameter");
	fd = open(token[1], O_RDONLY);
	if (fd < 0)
		ft_error("No such file or directory");
	if (read(fd, buf, 0) != 0)
		ft_error("Not a valid file");
	close(fd);
	cub->s = ft_strdup(token[1]);
	ft_printf("%s\n", cub->s);
}
