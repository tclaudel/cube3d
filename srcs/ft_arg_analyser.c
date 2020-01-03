/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_analyser.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:23:28 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 08:56:44 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static int		ft_params_completed(t_cub *cub)
{
	int		i;

	i = cub->res[0] > 0 && cub->res[1] > 0 && cub->no &&
		cub->so && cub->we && cub->ea && cub->s &&
		cub->c != -1 && cub->f != -1;
	return (i);
}

int				ft_arg_analyser(int fd, t_cub *cub)
{
	char	*line;

	while (ft_params_completed(cub) != 1 && get_next_line(fd, &line))
	{
		ft_convert_line(line, cub);
		free(line);
	}
	if ((!ft_params_completed(cub)))
		ft_error("Missing args");
	else
	{
		ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
		ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
		ft_printf("\t\t\tPARAMETERS COMPLETED\n");
		ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
		ft_printf("━━━━━━━━━━━━━━━━━━━━\n\n");
	}
	ft_check_map(fd, line, cub);
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
	ft_printf("\t\t\t    ANALYSIS DONE\n");
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
	return (1);
}
