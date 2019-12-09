/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_so_convert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:00:20 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 10:55:18 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_so_convert(const char **token, t_cube3d *cub)
{
	int		fd;
	char	*buf;

	buf = NULL;
	ft_dprintf(1, "CATCHING SO TEXTURE\t| ");
	if(token[2])
		ft_error("too many arguments for this parameter");
	fd = open(token[1], O_RDONLY);
	if (fd < 0)
		ft_error("No such file or directory");
	if (read(fd, buf, 0) != 0)
		ft_error("Not a valid file");
	close(fd); 
	cub->SO = ft_strdup(token[1]);
	ft_printfducul("path\t: %s\n", cub->SO);
}