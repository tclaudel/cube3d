/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:20:20 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 14:25:13 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_grep_flags(t_cub *cub, int ac, char **av)
{
	if (ac > 3)
		ft_error("please, give me only one flag");
	if (!ft_strncmp(av[2], "-m", 3))
		cub->flag = 'm';
	else if (!ft_strncmp(av[2], "-save", 6) ||
		!ft_strncmp(av[2], "--save", 7) || !ft_strncmp(av[2], "-s", 3))
		cub->flag = 's';
	else
		ft_error("wrong flag inserted");
}

int				main(int ac, char **av)
{
	int				fd;
	t_cub			*cub;
	char			*map;

	if (ac == 1)
		ft_error("please insert map");
	map = ft_strrchr(av[1], '.');
	if (ft_strncmp(".cub", map, 5))
		ft_error("Wrong map extension, should be .cub");
	if (!(fd = open(av[1], O_RDONLY)))
		ft_error("could not find the map");
	cub = init_cub();
	if (ac >= 3)
	{
		ft_grep_flags(cub, ac, av);
	}
	ft_arg_error(av[1]);
	ft_arg_analyser(fd, cub);
	ft_cub(cub);
	return (1);
}
