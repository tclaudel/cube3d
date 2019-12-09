/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 15:35:45 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 18:31:33 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"
void	ft_if_forest(const char **id, const char **token, t_cube3d *cub, int i)
{
	if (i == 0 && !strncmp(id[i], token[0], ft_strlen(id[i])))
		ft_r_convert(token, cub);
	if (i == 1 && !strncmp(id[i], token[0], ft_strlen(id[i])))
		ft_no_convert(token, cub);
	if (i == 2 && !strncmp(id[i], token[0], ft_strlen(id[i])))
		ft_so_convert(token, cub);
	if (i == 3 && !strncmp(id[i], token[0], ft_strlen(id[i])))
		ft_we_convert(token, cub);
	if (i == 4 && !strncmp(id[i], token[0], ft_strlen(id[i])))
		ft_ea_convert(token, cub);
	if (i == 5 && !strncmp(id[i], token[0], ft_strlen(id[i])))
		ft_s_convert(token, cub);
	// if (i == 6 && !strncmp(id[i], token[0], ft_strlen(id[i])))
	// 	ft_rconvert(token, cub);
	// if (i == 6 && !strncmp(id[i], token[0], ft_strlen(id[i])))
	// 	ft_rconvert(token, cub);
}

int		ft_convert_line(char *line, t_cube3d *cub)
{
	const char		*token[4];
	const char		*id[8] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C"};
	static int		i = 0;

	token[0] = ft_strtok(line, " ");
	token[1] = ft_strtok(NULL, " ");
	token[2] = ft_strtok(NULL, " ");
	token[3] = ft_strtok(NULL, " ");
	//dprintf(1, "%s\n%s\n%s\n%s\n", token[0], token[1], token[2], token[3]);
	if (!token[0])
		return(1);
	if (!strncmp(id[i], token[0], ft_strlen(id[i])) && (ft_strlen(token[0]) == ft_strlen(id[i])))
		ft_if_forest(id, token, cub, i);
	i++;
	return(1);
}