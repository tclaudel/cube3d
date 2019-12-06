/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:20:20 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 15:48:40 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

t_cube3d	*setup_struct(void)
{
	t_cube3d *setup;

	if (!(setup = malloc(sizeof(t_cube3d))))
		return (NULL);
	ft_bzero(setup->R, 2 * sizeof(char));
	setup->NO = 0;
	setup->SO = 0;
	setup->WE = 0;
	setup->EA = 0;
	setup->F = 0;
	setup->C = 0;
	return (setup);
}

int main(int ac, char **av)
{
	int			fd;
	t_cube3d	*pf;

	fd = open(av[1], O_RDONLY);
	pf = setup_struct();
	ft_arg_error(ac, av[1]);
	ft_arg_analyser(fd, pf);
	return(1);
}