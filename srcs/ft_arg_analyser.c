/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_analyser.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:23:28 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 17:59:49 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_arg_analyser(int fd, t_cube3d *pf)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		ft_convert_line(line, pf);
		if (line[0] == '1')
			break;
		dprintf(1, "%s", line);
		free(line);
	}
	return(1);
}