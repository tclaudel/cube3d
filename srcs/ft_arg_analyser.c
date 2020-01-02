/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_analyser.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:23:28 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 11:54:55 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static int		ft_params_completed(t_meta *meta)
{
	int		i;

	i = meta->cub->r[0] > 0 && meta->cub->r[1] > 0 && meta->cub->no &&
		meta->cub->so && meta->cub->we && meta->cub->ea && meta->cub->s &&
		meta->cub->c != -1 && meta->cub->f != -1;
	return (i);
}

int				ft_arg_analyser(int fd, t_meta *meta)
{
	char	*line;

	while (ft_params_completed(meta) != 1 && get_next_line(fd, &line))
	{
		ft_convert_line(line, meta);
		free(line);
	}
	if ((!ft_params_completed(meta)))
		ft_error("Missing args");
	else
	{
		ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
		ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
		ft_printf("\t\t\tPARAMETERS COMPLETED\n");
		ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
		ft_printf("━━━━━━━━━━━━━━━━━━━━\n\n");
	}
	ft_check_map(fd, line);
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
	ft_printf("\t\t\t    ANALYSIS DONE\n");
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
	return (1);
}
