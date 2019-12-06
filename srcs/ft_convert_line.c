/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 15:35:45 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 12:14:43 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_rconvert(char *line, t_cube3d *cub)
{
	char	*token;

	dprintf(1, "line\t: %s\n", line);
	token = ft_strtok(line, ' ');
	if (token)
		cub->R[0] = ft_atoi(token);
	else
		return (0);
	token = ft_strtok(line, ' ');
	if (token)
		cub->R[1] = ft_atoi(token);
	else
		return (0);
	ft_dprintf(1, "resultion : %d x %d\n",cub->R[0], cub->R[1]);
	return(1);
}

int		ft_convert_line(char *line, t_cube3d *cub)
{
	char	*token;
	int		error; 

	dprintf(1, "in\t: %s\n", line);
	if((token = ft_strtok(line, ' ')))
		error = 1;
	dprintf(1, "token\t: %s\n", token);
	token = ft_strtok(line, ' ');
	dprintf(1, "token1\t: %s\n", token);
	cub->R[0] = ft_atoi(token);

	return(1);
}