/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:20:20 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 08:44:13 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int			main(int ac, char **av)
{
	int				fd;
	t_cub			*cub;
	char			*map;

	map = ft_strrchr(av[1], '.');
	if (ft_strncmp(".cub", map, 5))
		ft_error("Wrong map extension, should be .cub");
	if (!(fd = open(av[1], O_RDONLY)))
		ft_error("could not find the map");
	cub = init_cub();
	ft_arg_error(ac, av[1]);
	ft_arg_analyser(fd, cub);
	ft_cub(cub);
	return (1);
}
