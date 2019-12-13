/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 15:35:45 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 10:25:08 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_yew_forest(char **token, t_cube3d *cub, t_color *color)
{
	if (!strncmp("R", token[0], 1) && ft_strlen(token[0]) == 1)
		ft_r_convert(token, cub);
	else if (!strncmp("NO", token[0], 1) && ft_strlen(token[0]) == 2)
		ft_no_convert(token, cub);
	else if (!strncmp("SO", token[0], 1) && ft_strlen(token[0]) == 2)
		ft_so_convert(token, cub);
	else if (!strncmp("WE", token[0], 1) && ft_strlen(token[0]) == 2)
		ft_we_convert(token, cub);
	else if (!strncmp("EA", token[0], 1) && ft_strlen(token[0]) == 2)
		ft_ea_convert(token, cub);
	else if (!strncmp("S", token[0], 1) && ft_strlen(token[0]) == 1)
		ft_s_convert(token, cub);
	else if (!strncmp("F", token[0], 1) && ft_strlen(token[0]) == 1)
		ft_f_convert(token, cub, color);
	else if (!strncmp("C", token[0], 1) && ft_strlen(token[0]) == 1)
		ft_c_convert(token, cub, color);
	else
		ft_error("wrong params");
}

int		ft_convert_line(char *line, t_meta *meta)
{
	char		*token[5];

	token[0] = ft_strtok(line, " ,\t");
	token[1] = ft_strtok(NULL, " ,\t");
	token[2] = ft_strtok(NULL, " ,\t");
	token[3] = ft_strtok(NULL, " ,\t");
	token[4] = ft_strtok(NULL, " ,\t");
	if (!token[0])
		return (1);
	ft_yew_forest(token, meta->cub, meta->color);
	return (1);
}
