/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:20:20 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 15:39:20 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

t_cube3d	*set_struct(void)
{
	t_cube3d *setup;

	if (!(setup = malloc(sizeof(t_cube3d))))
		return (NULL);
	setup->r = malloc(2 * sizeof(int));
	setup->no = 0;
	setup->so = 0;
	setup->we = 0;
	setup->ea = 0;
	setup->f = 0;
	setup->c = 0;
	return (setup);
}

int			main(int ac, char **av)
{
	int			fd;
	t_cube3d	*cub;

	fd = open(av[1], O_RDONLY);
	cub = set_struct();
	ft_arg_error(ac, av[1]);
	ft_arg_analyser(fd, cub);
	return (1);
}
