/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_analyser.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:23:28 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 15:38:32 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_arg_analyser(int fd, t_cube3d *cub)
{
	char	*line;
	// size_t	width;

	while (get_next_line(fd, &line))
	{
		ft_convert_line(line, cub);
		if (line[0] == '1')
			break;
		free(line);
	}
	if(!cub->r[0] || !cub->r[1] || !cub->no || !cub->so || !cub->we || !cub->ea || !cub->s)
		ft_error("Missing args");
	// while ((width = get_next_line(fd, &line)))
	// {
	// 	// ft_convert_map(line, cub);
	// }
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	ft_printf("\t\t\t\tANALYSIS DONE\n");
	ft_printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	//ft_lunch_window(cub);
	return(1);
}