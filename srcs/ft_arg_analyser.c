/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_analyser.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:23:28 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 18:21:03 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_arg_analyser(int fd, t_cube3d *cub)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		ft_convert_line(line, cub);
		if (line[0] == '1')
			break;
		free(line);
	}
	return(1);
}